#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Неверные размеры матрицы");
    }
    data.resize(rows, std::vector<T>(cols));
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(other.data) {
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > init) {
    rows = init.size();
    if (rows == 0) throw std::invalid_argument("Матрица не может быть пустой");
    cols = init.begin()->size();

    for (const auto &row: init) {
        if (row.size() != cols) {
            throw std::invalid_argument("Все строки должны иметь одинаковую длину");
        }
    }

    data.reserve(rows);
    for (const auto &row: init) {
        data.emplace_back(row);
    }
}

template<typename T>
T &Matrix<T>::get(size_t i, size_t j) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Индекс выходит за границы матрицы");
    }
    return data[i][j];
}

template<typename T>
const T &Matrix<T>::get(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Индекс выходит за границы матрицы");
    }
    return data[i][j];
}

template<typename T>
void Matrix<T>::set(size_t i, size_t j, const T &value) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Индекс выходит за границы матрицы");
    }
    data[i][j] = value;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Размеры матриц должны совпадать для сложения");
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Несовместимые размеры матриц для умножения");
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

template<typename U>
std::istream &operator>>(std::istream &is, Matrix<U> &matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

#endif // MATRIX_TPP
