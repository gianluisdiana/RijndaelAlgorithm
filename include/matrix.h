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
#include <iostream>

#include "functions.h"

#ifndef _MATRIX_H_
#define _MATRIX_H_

/**
 * @class Matrix
 * @brief Represents a bidemensional array
 *
 * @tparam T The data type contained in the matrix.
 */
template <class T>
class Matrix {
public:
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
 * @brief Overload of the << operator to print the matrix.
 *
 * @param os Represents the outflow.
 * @param matrix The matrix to print.
 * @tparam C The data type stored in the matrix.
 * @return The outflow with the matrixformated.
 */
  template <class C>
  friend std::ostream& operator<< (std::ostream& os, const Matrix<C>& matrix);

/**
 * @brief Make the transpose matrix
 *
 * @returns The transpose
 */
  Matrix transpose();

/**
 * @brief Overload of the [] operator.
 * Access the row of the given index.
 *
 * @returns The row selected of the matrix
 */
  std::vector<T>& operator[] (const size_t index);

/**
 * @brief Overload of the ^ (XOR) operator.
 * Performs an element-by-element xor operation with the other matrix.
 *
 * @param matrix The matrix to operate with.
 *
 * @return The result matrix with its elements being the XOR operation.
 */
  Matrix operator^ (Matrix& matrix);

/**
 * @brief Convert the matrix in a string
 *
 * @returns A string equivalent to the matrix.
 */
  std::string toString();

/**
 * @brief Get the amount of rows.
 *
 * @return The amount of rows the matrix has.
 */
  size_t amountRows();

private:
  size_t _amount_rows; // The amount of rows the matrix has
  size_t _amount_cols; // The amount of columns the matrix has
  std::vector<std::vector<T>> _matrix; // The matrix itself
};

template <class T>
Matrix<T>::Matrix (const size_t amount_rows, const size_t amount_cols) {
  this->_amount_rows = amount_rows;
  this->_amount_cols = amount_cols;

  this->_matrix.resize(amount_rows);
  for (size_t i = 0; i < amount_cols; ++i) this->_matrix[i].resize(amount_cols);
}

template <class T>
Matrix<T>::Matrix (std::string str, const size_t amount_rows, const size_t amount_cols) {
  if (str.size() < amount_rows * amount_cols) str = formatText(str, amount_rows * amount_cols);
  this->_amount_rows = amount_rows;
  this->_amount_cols = amount_cols;

  for (size_t i = 0; i < amount_rows * amount_cols; ++i) {
    if (i % amount_cols == 0) this->_matrix.push_back(std::vector<T>());
    this->_matrix[int(i / amount_rows)].push_back(T(str[i]));
  }
}

template <class T>
template <size_t amount_rows, size_t amount_cols>
Matrix<T>::Matrix (T (&matrix)[amount_rows][amount_cols]) {
  this->_amount_rows = amount_rows;
  this->_amount_cols = amount_cols;

  for (size_t i = 0; i < this->_amount_rows; ++i) {
    this->_matrix.push_back(std::vector<T>());
    this->_matrix[i].assign(matrix[i], matrix[i] + this->_amount_cols);
  }
  std::cout << *this << std::endl;
}

template <class T>
size_t Matrix<T>::amountRows() {
  return this->_amount_rows;
}

template <class C>
std::ostream& operator<< (std::ostream& os, const Matrix<C>& matrix) {
  os << "[\n";
  for (auto& row : matrix._matrix) {
    os << "\t[";
    for (size_t i = 0; i < row.size() - 1; ++i)
      os << row[i] << ", ";
    os << row[row.size() - 1] << "]\n";
  }
  os << "]";
  return os;
}

template <class T>
std::vector<T>& Matrix<T>::operator[] (const size_t index) {
  return this->_matrix[index];
}

template <class T>
Matrix<T> Matrix<T>::operator^ (Matrix& matrix) {
  if (matrix._amount_rows != this->_amount_rows || matrix._amount_cols != this->_amount_cols) {
    std::cerr << "The matrixes must be the same size\n";
    exit(1);
  }
  Matrix result(this->_amount_rows, this->_amount_cols);

  for (size_t row_index = 0; row_index < this->_amount_rows; ++row_index) {
    for (size_t col_index = 0; col_index < this->_amount_cols; ++col_index) {
      result[row_index][col_index] = this->_matrix[row_index][col_index] ^ matrix[row_index][col_index];
    }
  }
  return result;
}

template <class T>
Matrix<T> Matrix<T>::transpose() {
  Matrix transposed(this->_amount_rows, this->_amount_cols);

  for (size_t row_index = 0; row_index < this->_amount_rows; ++row_index) {
    for (size_t col_index = 0; col_index < this->_amount_cols; ++col_index) {
      transposed[col_index][row_index] = this->_matrix[row_index][col_index];
    }
  }
  return transposed;
}

template <class T>
std::string Matrix<T>::toString() {
  std::string matrix_string = "";

  for (auto& row : this->_matrix) {
    for (size_t i = 0; i < row.size(); ++i) {
      matrix_string += row[i];
    }
  }
  return matrix_string;
}

#endif // _MATRIX_H_