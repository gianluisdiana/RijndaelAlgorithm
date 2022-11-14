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

  if (argc == 2) {
    if (input[1] == "--help") {
      help();
      exit(0);
    }
    std::cerr << "Use --help for more info\n";
    usage();
    exit(1);
  }

  if (argc != 3 && argc != 4) {
    std::cerr << "Use --help for more info\n";
    usage();
    exit(1);
  }

  if (argc == 4 && getIndex<std::string>(input, "--hex") == -1) {
    std::cerr << "If you use 4 parameteres, one of them must be '--hex'\n";
    usage();
    exit(1);
  }

  int decrypt_index = getIndex<std::string>(input, "--decrypt");
  int encrypt_index = getIndex<std::string>(input, "--encrypt");

  if (encrypt_index == -1 && decrypt_index == -1) {
    std::cerr << "You need to select one mode <encrypt | decrypt>\n";
    usage();
    exit(1);
  }

  if (encrypt_index != -1 && decrypt_index != -1) {
    std::cerr << "You must select just one mode\n";
    usage();
    exit(1);
  }

  size_t mode_index = encrypt_index != -1 ? encrypt_index : decrypt_index;

  if (mode_index == input.size() - 1) {
    std::cerr << "You must introduced first the mode <encrypt | decrypt> and then the word\n";
    usage();
    exit(1);
  }

  if (input[mode_index + 1] == "--hex") {
    std::cerr << "After the mode must be the key to work with\n";
    usage();
    exit(1);
  }

  std::cout << "The mode selected is: " << (encrypt_index != -1 ? "encrypt\n" : "decrypt\n");
}

int getModeIndex(const int argc, char* argv[]) {
  std::vector<std::string> input;
  input.assign(argv, argv + argc);
  int decrypt_index = getIndex<std::string>(input, "--decrypt");
  int encrypt_index = getIndex<std::string>(input, "--encrypt");

  return encrypt_index != -1 ? encrypt_index : decrypt_index;
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

std::string decToHex(const int number) {
  const char EQUIVALENT[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int result = number;
  std::string inverted_hex = "";

  while (result > 15) {
    inverted_hex += EQUIVALENT[result % 16];
    result = result / 16;
  }

  if (result != 0) inverted_hex += EQUIVALENT[result];
  return reverseString(inverted_hex);
}