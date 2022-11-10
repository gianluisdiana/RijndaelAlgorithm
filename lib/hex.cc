/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file hex.cc
 * @version 0.2
 * @brief Treasure Hunt
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
#include "../include/hex.h"

#include <iostream>
#include <cmath>

#include "../include/functions.h"

const std::vector<char> Hex::equivalent = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

std::string Hex::decimalToHex(int number) {
  int result = number;
  std::string inverted_hex = "";

  while (result > 15) {
    inverted_hex += Hex::equivalent[result % 16];
    result = result / 16;
  }

  if (result != 0) inverted_hex += Hex::equivalent[result];
  return reverseString(inverted_hex);
}

int Hex::hexToDecimal(std::string hex_value) {
  int result = 0;
  int current_index = hex_value.length() - 1;

  for (size_t i = 0; i < hex_value.length(); ++i) {
    result += getIndex<char>(Hex::equivalent, hex_value[i]) * pow(16, current_index);
    --current_index;
  }

  return result;
}

Hex::Hex(std::string hex_value) {
  this->_hex_value = hex_value;
}

Hex::Hex(int number) {
  this->_hex_value = Hex::decimalToHex(number);
}

int Hex::toInt() {
  return Hex::hexToDecimal(this->_hex_value);
}

Hex Hex::operator^(Hex& hex) {
  return Hex(this->toInt() ^ hex.toInt());
}

std::ostream& operator<< (std::ostream& os, const Hex& hex) {
  os << hex._hex_value;
  return os;
}

Hex::operator char () {
  return char(Hex::hexToDecimal(this->_hex_value));
};

char Hex::operator[] (const size_t index) {
  return this->_hex_value.length() <= index ? '0' : this->_hex_value[index];
}