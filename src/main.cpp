/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file main.cc
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
#include <iostream>

#include "../include/functions.hpp"
#include "../include/rijndael.hpp"

int main(int argc, char* argv[]) {
  checkInput(argc, argv);

  bool show_hex = argc == 4;
  int mode_index = getModeIndex(argc, argv);
  std::string option = argv[mode_index];
  Rijndael rijndael(argv[mode_index + 1]);

  if (option == "--encrypt") {
    rijndael.encrypt();
    std::cout << "Text encrypted: " << rijndael.text() << "\n";
  } else if (option == "--decrypt") {
    rijndael.decrypt();
    std::cout << "Text decrypted: " << rijndael.text() << "\n";
  }

  if (show_hex) std::cout << "Hex code: " << rijndael.toHex() << "\n";

  return 0;
}