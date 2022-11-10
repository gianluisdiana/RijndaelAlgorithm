/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file hex.h
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
#include<string>
#include<vector>

#ifndef _HEX_H_
#define _HEX_H_

/**
 * @class Hex
 * @brief Represent an hexadecimal value
 */
class Hex {
public:
/**
 * @brief Construct a new Hex object from an integer
 *
 * @param number The number to refer
 */
  Hex(int number = 0);

/**
 * @brief Construct a new Hex object from an hexadecimal
 *
 * @param hex_value An string with the haxadecimal value
 */
  Hex(std::string hex_value);

/**
 * @brief Convert a decimal to hexadecimal.
 *
 * @param number The decimal to convert.
 * @return Its equivalent in hexadecimal base.
 */
  static std::string decimalToHex(int number);

/**
 * @brief Convert an hexadecimal value to decimal;
 *
 * @param hex_value The hex value to convert.
 * @return Its equivalent in decimal base.
 */
  static int hexToDecimal(std::string hex_value);

  /**
   * @brief Convert its hex value to decimal base.
   *
   * @return The decimal value of the number
   */
  int toInt();

  /**
   * @brief Overload the ^ operator with the int value.
   *
   * @param hex The second hex object to operate with.
   * @return A new Hex object, being the result of the operation.
   */
  Hex operator^(Hex& hex);

  /**
   * @brief Makes the implicit conversion from char to Hex.
   */
  operator char ();

  /**
   * @brief Bring access to the hex value using [].
   *
   * @param index The position of the character to access.
   * @return The digit in the given position.
   */
  char operator[] (const size_t index);

  /**
 * @brief Overload of the << operator.
 *
 * @param os Represents the outflow.
 * @param hex Is the hexadecimal value to print.
 * @return The outflow with the hex formated.
 */
  friend std::ostream& operator<< (std::ostream& os, const Hex& hex);

  static const std::vector<char> equivalent;  // The conversion from decimal to hexadecimal.

private:
  std::string _hex_value; // The hexadecimal representation
};

#endif // _HEX_H_