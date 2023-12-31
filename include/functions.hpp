/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file functions.hpp
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
#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief Tell the user how to use the program
 */
void usage();

/**
 * @brief Provides help to the user to execute the program properly
 */
void help();

/**
 * @brief Check if the program was called as expected
 *
 * @param argc The amount of parameters introduced with the program
 * @param argv A list with the parameters
 */
void checkInput(const int argc, char* argv[]);

/**
 * @brief Get the index of the mode selected in the input array
 *
 * @param argc The amount of parameters introduced with the program
 * @param argv A list with the parameters
 * @return The index of the mode selected
 */
int getModeIndex(const int argc, char* argv[]);

/**
 * @brief Complete the string with a padding character
 *
 * @param text The text to format
 * @param size The size that the text will have after the padding
 * @param padding_char The character to add to the string
 */
std::string formatText(std::string text, const size_t size, const char padding_char = ' ');

/**
 * @brief Loop the string from the end to the beginnig, setting the reversed string
 *
 * @param str The string to reverse
 * @return The reversed string
 */
std::string reverseString(std::string str);

/**
 * @brief Convert a decimal to hexadecimal.
 *
 * @param number The decimal to convert.
 * @return Its equivalent in hexadecimal base.
 */
std::string decToHex(const int number);

/**
 * @brief Get the the index of an element.
 *
 * @tparam T The data type of the vector
 *
 * @param vector The vector to see its content.
 * @param element The element to search.
 *
 * @return The position of the element. -1 if it wasn't in the vector.
 */
template <class T>
int getIndex(std::vector<T> vector, T element) {
  auto it = std::find(vector.begin(), vector.end(), element);
  return it != vector.end() ? it - vector.begin() : -1;
}

/**
 * @brief Shift a vector "offset" times
 *
 * @tparam T The data type of the vector
 * @param vector Array to shift
 * @param offset The amount of times the vector will be shift
 * @return A vector shifted
 */
template <class T>
std::vector<T> shiftVector(const std::vector<T> &vector, const int offset) {
  std::vector<T> shifted_vector;
  // Starting at the offset position
  for (size_t i = offset; i < vector.size(); ++i) shifted_vector.push_back(vector[i]);
  // Adding the rest
  for (int i = 0; i < offset; ++i) shifted_vector.push_back(vector[i]);

  return shifted_vector;
}

/**
 * @brief Shift from the end a vector "offset" times
 *
 * @tparam T The data type of the vector
 * @param vector Array to ushift
 * @param offset The amount of times the vector will be permutated
 * @return The vector unshifted
 */
template <class T>
std::vector<T> unshiftVector(const std::vector<T> &vector, const int offset) {
  // std::vector<T> unshifted_vector;
  // // Starting at the offset position (from the end)
  // for (size_t i = vector.size() - offset; i < vector.size(); ++i) unshifted_vector.push_back(vector[i]);
  // // Adding the rest
  // for (size_t i = 0; i < vector.size() - offset; ++i) unshifted_vector.push_back(vector[i]);

  // return unshifted_vector;
  return shiftVector(vector, vector.size() - offset);
}

#endif // _FUNCTIONS_HPP_