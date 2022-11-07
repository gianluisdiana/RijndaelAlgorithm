/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file functions.cc
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
#include "../include/functions.h"

#include <iostream>
#include <algorithm>

void usage() {
  std::cout << "Introduce the key when executing the code:\n"
            << "./exec.out <key>\n";
}

void checkInput(int argc) {
  if (argc == 2) return;
  usage();
  exit(1);
}