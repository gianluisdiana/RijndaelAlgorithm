/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file rijndael.h
 * @version 0.3
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
#ifndef _RIJNDAEL_H_
#define _RIJNDAEL_H_

#include "matrix.h"

/**
 * @class Rijndael
 * @brief Represents the cipher algorithm Rijndael or AES
 */
class Rijndael {
public:
  /**
   * @brief Construct a new Rijndael object
   *
   * @param text The text to encrypt
   */
  Rijndael(const std::string text);

  /**
   * @brief Starts the algoritm
   */
  void encrypt();

  /**
   * @brief Reverse the algoritm.
   */
  void decrypt();

  /**
   * @brief Convert the text matrix in a string and returns it
   *
   * @returns the text encrypted
   */
  std::string text();

private:
  // ----- ENCRYPT -----
  /**
   * @brief Performs an element-by-element xor operation with the encryption
   * matrix.
   */
  void addRoundKey();

  /**
   * @brief Substitutes the bytes for its equivalent in the table.
   */
  void subBytes();

  /**
   * @brief Permutate the rows of the matrix.
   */
  void shiftRows();

  // ----- DECRYPT -----

  /**
   * @brief Revert the sustitution made with the box.
   */
  void invSubBytes();

  /**
   * @brief Revert the permutation made.
   * Rotate, from the end, each row depending on its position
   */
  void invShiftRows();

  static const uint32_t s_box[16][16];          // Box to substitute values with
  static const uint32_t inverse_s_box[16][16];  // Box to reverse the substitute done
  static std::string _encryption_key;           // Key used to encrypt the text
  Matrix<uint32_t> _text_matrix;                // A matrix with the text to encrypt
  Matrix<uint32_t> _encryption_matrix;          // A matrix with the private key encrypted
};

#endif // _RIJNDAEL_H_