/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file functions.cc
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
#include "../include/functions.h"

#include <iostream>

void usage() {
  std::cout << "Introduce the key when executing the code:\n"
            << "./exec.out <key>\n";
}

void checkInput(int argc) {
  if (argc == 2) return;
  usage();
  exit(1);
}

std::string formatText(std::string text, const size_t size, const char padding_char) {
  while (text.size() < size) text += padding_char;
  return text;
}

std::string reverseString(const std::string str) {
  std::string reversed_string = "";
  for (int i = str.length() - 1; i >= 0; --i)
    reversed_string += str[i];
  return reversed_string;
}