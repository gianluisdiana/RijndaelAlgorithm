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
#include <sstream>

#include "../include/input_error.h"

void usage() {
  std::cout << "./bin/exec.out [--hex] <--encrypt | --decrypt> <key>\n";
}

void help() {
  std::cout << "This program encrypt or decrypt a key using the Rijndael algorithm "
            << "and a private key.\n";
  usage();
  std::cout << "\t\t  │\t\t  │\t\t └─> The key to encrypt / decrypt\n"
            << "\t\t  │\t\t  └─> The mode selected\n"
            << "\t\t  └─> If we want to display the result hex code. Optional.\n";
}

void checkInput(const int argc, char* argv[]) {
  std::vector<std::string> input;
  input.assign(argv, argv + argc);

  try {
    if (argc == 2) {
      if (input[1] == "--help") {
        help();
        exit(0);
      }
      throw InputError("Use --help for more info\n");
    }

    if (argc != 3 && argc != 4) throw InputError("Use --help for more info\n");

    if (argc == 4 && getIndex<std::string>(input, "--hex") == -1)
      throw InputError("If you use 4 parameteres, one of them must be '--hex'\n");

    int decrypt_index = getIndex<std::string>(input, "--decrypt");
    int encrypt_index = getIndex<std::string>(input, "--encrypt");

    if (encrypt_index == -1 && decrypt_index == -1)
      throw InputError("You need to select one mode <encrypt | decrypt>\n");

    if (encrypt_index != -1 && decrypt_index != -1)
      throw InputError("You must select just one mode\n");

    size_t mode_index = encrypt_index != -1 ? encrypt_index : decrypt_index;

    if (mode_index == input.size() - 1)
      throw InputError("You must introduced first the mode <encrypt | decrypt> and then the word\n");

    if (input[mode_index + 1] == "--hex")
      throw InputError("After the mode must be the key to work with\n");
  } catch (const InputError& e) {
    std::cout << e.getMessage();
    usage();
    exit(1);
  }
}

int getModeIndex(const int argc, char* argv[]) {
  std::vector<std::string> input;
  input.assign(argv, argv + argc);
  const int decrypt_index = getIndex<std::string>(input, "--decrypt");
  const int encrypt_index = getIndex<std::string>(input, "--encrypt");

  return encrypt_index != -1 ? encrypt_index : decrypt_index;
}

std::string formatText(std::string text, const size_t size, const char padding_char) {
  if (text.size() > size) return text.substr(0, size);
  return text + std::string(size - text.size(), padding_char);
}

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

std::string decToHex(const int number) {
  std::stringstream stream;
  stream << std::hex << number;
  return stream.str();
}