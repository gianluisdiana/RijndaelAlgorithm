/**
 * @author Gian Luis Bolivar Diana (gianluisbolivar1@gmail.com)
 * @date November 7, 2022
 *
 * @file matrix.h
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

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

#include "functions.h"

/**
 * @brief Represents a bidemensional array
 *
 * @tparam T The data type contained in the matrix.
 */
template <class T>
class Matrix {
 public:
  // ----------------------------- Constructors ----------------------------- //
  /**
   * @brief Empty constructor, only reserve the size of the matrix
   *
   * @param amount_rows The amount of rows the matrix will have
   * @param amount_cols The amount of columns the matrix will have
   */
  Matrix(const size_t amount_rows = 1, const size_t amount_cols = 1);

  /**
   * @brief Initialize the matrix with an string.
   *
   * @param str The string to convert in a matrix.
   * @param amount_rows The amount of rows the matrix will have
   * @param amount_cols The amount of columns the matrix will have
   */
  Matrix(std::string str, const size_t amount_rows, const size_t amount_cols);

  /**
   * @brief Initialize the matrix with an bidimensional array of the type.
   *
   * @tparam amount_rows The amount of rows the 2D array has.
   * @tparam amount_cols The amount of cols the 2D array has.
   * @param matrix The bidemensional array to get the data from.
   */
  template <size_t amount_rows, size_t amount_cols>
  Matrix(T (&matrix)[amount_rows][amount_cols]);

  /**
   * @brief Make the transpose matrix
   *
   * @returns The transpose
   */
  Matrix transpose();

  /**
   * @brief Convert the matrix in a string
   *
   * @returns A string equivalent to the matrix.
   */
  std::string toString();

  /**
   * @brief Makes a string with the hex value of each element contained in the matrix
   *
   * @return A string with the equivalent hexadecimal value of each element
   */
  std::string toHexString();

  // ------------------------------- Operators ------------------------------- //

  /**
   * @brief Overload of the [] operator.
   * Access the row of the given index.
   *
   * @param index The index of the row to access.
   * @returns The row selected of the matrix
   */
  std::vector<T>& operator[](const size_t index);

  /**
   * @brief Overload of the ^ (XOR) operator.
   * Performs an element-by-element xor operation with the other matrix.
   *
   * @param matrix The matrix to operate with.
   * @return The result matrix with its elements being the XOR operation.
   */
  Matrix operator^(Matrix& matrix);

  /**
   * @brief Overload of the << operator to print the matrix.
   *
   * @param os Represents the outflow.
   * @param matrix The matrix to print.
   * @tparam C The data type stored in the matrix.
   * @return The outflow with the matrixformated.
   */
  template <class C>
  friend std::ostream& operator<<(std::ostream& os, const Matrix<C>& matrix);

 private:
  // The amount of rows the matrix has
  size_t _rows_amount;
  // The amount of columns the matrix has
  size_t _cols_amount;
  // The data stored in the matrix
  std::vector<std::vector<T>> _data;
};

template <class T>
Matrix<T>::Matrix(const size_t amount_rows, const size_t amount_cols) :
  _rows_amount(amount_rows),
  _cols_amount(amount_cols)
  {
  _data.resize(amount_rows);
  for (auto& row : _data) row.resize(amount_cols);
}

template <class T>
Matrix<T>::Matrix(std::string str, const size_t amount_rows, const size_t amount_cols) :
  _rows_amount(amount_rows),
  _cols_amount(amount_cols)
  {
  str = formatText(str, amount_rows * amount_cols);
  for (size_t i = 0; i < str.size(); ++i) {
    if (i % amount_cols == 0) _data.push_back(std::vector<T>());
    _data[int(i / amount_rows)].push_back(T(str[i]));
  }
}

template <class T>
template <size_t amount_rows, size_t amount_cols>
Matrix<T>::Matrix(T (&matrix)[amount_rows][amount_cols]) :
  _rows_amount(amount_rows),
  _cols_amount(amount_cols)
  {
  for (size_t i = 0; i < _rows_amount; ++i) {
    _data.push_back(std::vector<T>());
    _data[i].assign(matrix[i], matrix[i] + _cols_amount);
  }
}

template <class T>
Matrix<T> Matrix<T>::transpose() {
  Matrix transposed(_rows_amount, _cols_amount);
  for (size_t row_index = 0; row_index < _rows_amount; ++row_index) {
    for (size_t col_index = 0; col_index < _cols_amount; ++col_index) {
      transposed[col_index][row_index] = _data[row_index][col_index];
    }
  }
  return transposed;
}

template <class T>
std::string Matrix<T>::toString() {
  std::string matrix_string = "";
  for (const auto& row : _data) {
    for (const auto& element : row) {
      matrix_string += element;
    }
  }
  return matrix_string;
}

template <class T>
std::string Matrix<T>::toHexString() {
  std::string matrix_hex_string = "";
  for (const auto& row : _data) {
    for (const auto& element : row) {
      matrix_hex_string += decToHex(element);
    }
  }
  return matrix_hex_string;
}

template <class T>
std::vector<T>& Matrix<T>::operator[](const size_t index) {
  return _data[index];
}

template <class T>
Matrix<T> Matrix<T>::operator^(Matrix& matrix) {
  if (matrix._rows_amount != _rows_amount || matrix._cols_amount != _cols_amount) {
    std::cerr << "The matrixes must be the same size\n";
    exit(1);
  }
  Matrix result(_rows_amount, _cols_amount);
  for (size_t row_index = 0; row_index < _rows_amount; ++row_index) {
    for (size_t col_index = 0; col_index < _cols_amount; ++col_index) {
      result[row_index][col_index] = _data[row_index][col_index] ^ matrix[row_index][col_index];
    }
  }
  return result;
}

template <class C>
std::ostream& operator<<(std::ostream& os, const Matrix<C>& matrix) {
  os << "[\n";
  for (auto& row : matrix._data) {
    os << "\t[";
    for (size_t i = 0; i < row.size() - 1; ++i)
      os << row[i] << ", ";
    os << row[row.size() - 1] << "]\n";
  }
  os << "]";
  return os;
}

#endif // _MATRIX_H_