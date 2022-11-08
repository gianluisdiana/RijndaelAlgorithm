/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file rijndael.cc
 * @version 0.2
 * @brief Teasure Hunt
 *    This program was made to uncode a password that has to be discovered by
 * putting together multiples hints that were hide around our college building
 * as an activity for the CESINF (Congreso de Estudiantes de Ingenieria
 * Informatica or Computer Science Students Congress).
 *
 * @see AES information: @link https://es.wikipedia.org/wiki/Advanced_Encryption_Standard @endlink
 * @see Github repository: @link https://github.com/gianluisdiana/RijndaelAlgorithm @endlink
 * @see CESINF page: @link https://www.cesinfull.com/ @endlink
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/rijndael.h"

#include "../include/functions.h"

const Hex Rijndael::substitution_box[16][16] = {
  {Hex("63"), Hex("7C"), Hex("77"),	Hex("7B"), Hex("F2"), Hex("6B"), Hex("6F"), Hex("C5"), Hex("30"), Hex("01"), Hex("67"), Hex("2B"), Hex("FE"),	Hex("D7"), Hex("AB"),	Hex("76")},
  {Hex("CA"), Hex("82"), Hex("C9"),	Hex("7D"), Hex("FA"), Hex("59"), Hex("47"), Hex("F0"), Hex("AD"), Hex("D4"), Hex("A2"), Hex("AF"), Hex("9C"),	Hex("A4"), Hex("72"),	Hex("C0")},
  {Hex("B7"), Hex("FD"), Hex("93"),	Hex("26"), Hex("36"), Hex("3F"), Hex("F7"), Hex("CC"), Hex("34"), Hex("A5"), Hex("E5"), Hex("F1"), Hex("71"),	Hex("D8"), Hex("31"),	Hex("15")},
  {Hex("04"), Hex("C7"), Hex("23"),	Hex("C3"), Hex("18"), Hex("96"), Hex("05"), Hex("9A"), Hex("07"), Hex("12"), Hex("80"), Hex("E2"), Hex("EB"),	Hex("27"), Hex("B2"),	Hex("75")},
  {Hex("09"), Hex("83"), Hex("2C"),	Hex("1A"), Hex("1B"), Hex("6E"), Hex("5A"), Hex("A0"), Hex("52"), Hex("3B"), Hex("D6"), Hex("B3"), Hex("29"),	Hex("E3"), Hex("2F"),	Hex("84")},
  {Hex("53"), Hex("D1"), Hex("00"),	Hex("ED"), Hex("20"), Hex("FC"), Hex("B1"), Hex("5B"), Hex("6A"), Hex("CB"), Hex("BE"), Hex("39"), Hex("4A"),	Hex("4C"), Hex("58"),	Hex("CF")},
  {Hex("D0"), Hex("EF"), Hex("AA"),	Hex("FB"), Hex("43"), Hex("4D"), Hex("33"), Hex("85"), Hex("45"), Hex("F9"), Hex("02"), Hex("7F"), Hex("50"),	Hex("3C"), Hex("9F"),	Hex("A8")},
  {Hex("51"), Hex("A3"), Hex("40"),	Hex("8F"), Hex("92"), Hex("9D"), Hex("38"), Hex("F5"), Hex("BC"), Hex("B6"), Hex("DA"), Hex("21"), Hex("10"),	Hex("FF"), Hex("F3"),	Hex("D2")},
  {Hex("CD"), Hex("0C"), Hex("13"),	Hex("EC"), Hex("5F"), Hex("97"), Hex("44"), Hex("17"), Hex("C4"), Hex("A7"), Hex("7E"), Hex("3D"), Hex("64"),	Hex("5D"), Hex("19"),	Hex("73")},
  {Hex("60"), Hex("81"), Hex("4F"),	Hex("DC"), Hex("22"), Hex("2A"), Hex("90"), Hex("88"), Hex("46"), Hex("EE"), Hex("B8"), Hex("14"), Hex("DE"),	Hex("5E"), Hex("0B"),	Hex("DB")},
  {Hex("E0"), Hex("32"), Hex("3A"),	Hex("0A"), Hex("49"), Hex("06"), Hex("24"), Hex("5C"), Hex("C2"), Hex("D3"), Hex("AC"), Hex("62"), Hex("91"),	Hex("95"), Hex("E4"),	Hex("79")},
  {Hex("E7"), Hex("C8"), Hex("37"),	Hex("6D"), Hex("8D"), Hex("D5"), Hex("4E"), Hex("A9"), Hex("6C"), Hex("56"), Hex("F4"), Hex("EA"), Hex("65"),	Hex("7A"), Hex("AE"),	Hex("08")},
  {Hex("BA"), Hex("78"), Hex("25"),	Hex("2E"), Hex("1C"), Hex("A6"), Hex("B4"), Hex("C6"), Hex("E8"), Hex("DD"), Hex("74"), Hex("1F"), Hex("4B"),	Hex("BD"), Hex("8B"),	Hex("8A")},
  {Hex("70"), Hex("3E"), Hex("B5"),	Hex("66"), Hex("48"), Hex("03"), Hex("F6"), Hex("0E"), Hex("61"), Hex("35"), Hex("57"), Hex("B9"), Hex("86"),	Hex("C1"), Hex("1D"),	Hex("9E")},
  {Hex("E1"), Hex("F8"), Hex("98"),	Hex("11"), Hex("69"), Hex("D9"), Hex("8E"), Hex("94"), Hex("9B"), Hex("1E"), Hex("87"), Hex("E9"), Hex("CE"),	Hex("55"), Hex("28"),	Hex("DF")},
  {Hex("8C"), Hex("A1"), Hex("89"),	Hex("0D"), Hex("BF"), Hex("E6"), Hex("42"), Hex("68"), Hex("41"), Hex("99"), Hex("2D"), Hex("0F"), Hex("B0"),	Hex("54"), Hex("BB"),	Hex("16")}
};

std::string Rijndael::_encryption_key = "ULL_C0ngR350-1nF";

Rijndael::Rijndael(std::string text) {
  text = text.size() == 16 ? text : formatText(text, 16);
  _text_matrix = Matrix<Hex>(text, 4, 4).transpose();
  _encryption_matrix = Matrix<Hex>(_encryption_key, 4, 4).transpose();
}

std::string Rijndael::text() {
  return this->_text_matrix.transpose().toString();
}

// ------------------ ENCRYPT ------------------

void Rijndael::addRoundKey() {
  this->_text_matrix = this->_text_matrix ^ this->_encryption_matrix;
}

void Rijndael::subBytes() {
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      int row = getIndex(Hex::equivalent, this->_text_matrix[i][j][0]);
      int col = getIndex(Hex::equivalent, this->_text_matrix[i][j][1]);
      this->_text_matrix[i][j] = Rijndael::substitution_box[row][col];
    }
  }
}

void Rijndael::encrypt() {
  this->addRoundKey();
  // this->subBytes();
}

// ------------------ DECRYPT ------------------

void Rijndael::invAddRoundKey() {
  this->_text_matrix = this->_text_matrix ^ this->_encryption_matrix;
}

void Rijndael::decrypt() {
  invAddRoundKey();
}