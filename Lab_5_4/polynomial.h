#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class Polynomial {
private:
    std::vector<T> coeffs;

    void normalize() {
        size_t new_size = coeffs.size();
        while (new_size > 1 && coeffs[new_size - 1] == T(0)) {
            new_size--;
        }
        coeffs.resize(new_size);
    }

public:
    // Конструкторы
    Polynomial() : coeffs(1, T(0)) {}
    explicit Polynomial(const T& scalar) : coeffs(1, scalar) {}
    Polynomial(const std::vector<T>& coefficients) : coeffs(coefficients) {
        normalize();
    }

    // Степень многочлена
    size_t Degree() const {
        return coeffs.size() - 1;
    }

    // Доступ к коэффициентам
    const T& operator[](size_t degree) const {
        static const T zero = T(0);
        return degree < coeffs.size() ? coeffs[degree] : zero;
    }

    // Операторы сравнения
    bool operator==(const Polynomial& other) const {
        return coeffs == other.coeffs;
    }
    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    // Арифметические операторы
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);

    // Оператор вычисления значения
    T operator()(const T& x) const {
        T result = T(0);
        T power = T(1); // x^0

        for (size_t i = 0; i < coeffs.size(); ++i) {
            result = result + (coeffs[i] * power);
            power = power * x;
        }

        return result;
    }

    // Оператор вывода
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Polynomial<U>& poly);
};

#include "polynomial.tpp"

#endif // POLYNOMIAL_H