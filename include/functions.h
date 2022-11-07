/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file functions.h
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
#include <string>
#include <vector>

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
 */
void checkInput(int argc);

#endif // _FUNTIONS_H_