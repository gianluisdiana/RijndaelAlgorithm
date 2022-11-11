/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file functions.h
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
#include <algorithm>
#include <string>
#include <vector>

template <class T>
class Matrix;

#ifndef _FUNTIONS_H_
#define _FUNTIONS_H_

/**
 * @brief Tell the user how to use the program
 */
void usage();

/**
 * @brief Check if the program was called as expected
 *
 * @param argc The amount of parameters introduced with the program
 * @param argv A list with the parameters
 */
void checkInput(int argc, char* argv[]);

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
std::string reverseString(const std::string str);

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

#endif // _FUNTIONS_H_