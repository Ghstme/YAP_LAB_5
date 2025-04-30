#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T> > data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);

    Matrix(const Matrix &other);

    Matrix(std::initializer_list<std::initializer_list<T> > init);

    ~Matrix() = default;

    // Методы доступа
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    T &get(size_t i, size_t j);

    const T &get(size_t i, size_t j) const;

    void set(size_t i, size_t j, const T &value);

    // Операторы
    Matrix operator+(const Matrix &other) const;

    Matrix operator*(const Matrix &other) const;

    Matrix &operator=(const Matrix &other);

    // Дружественные операторы ввода/вывода
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);

    template<typename U>
    friend std::istream &operator>>(std::istream &is, Matrix<U> &matrix);
};

#include "matrix.tpp"

#endif // MATRIX_H
