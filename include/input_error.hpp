/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 15, 2022
 *
 * @file input_error.hpp
 * @version 0.3.2
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
#ifndef _INPUT_ERROR_HPP_
#define _INPUT_ERROR_HPP_

#include <exception>
#include <string>

/**
 * @class InputError
 * @brief Represent argument input errors
 */
class InputError : public std::exception {
public:
  /**
   * @brief Construct a new Input Error object with a message
   *
   * @param message A descriptive message explaining the error
   */
  InputError(std::string message = "") : _message(message) {};

  /**
   * @brief Get the message of the error
   *
   * @return The error message produced
   */
  std::string getMessage() const;

private:
  std::string _message;
};

#endif // _INPUT_ERROR_HPP_