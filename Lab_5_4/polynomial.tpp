#ifndef POLYNOMIAL_TPP
#define POLYNOMIAL_TPP

#include "polynomial.h"

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const {
    size_t max_size = coeffs.size() > other.coeffs.size() ? coeffs.size() : other.coeffs.size();
    std::vector<T> result_coeffs(max_size, T(0));

    for (size_t i = 0; i < max_size; ++i) {
        result_coeffs[i] = (*this)[i] + other[i];
    }

    return Polynomial<T>(result_coeffs);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other) const {
    size_t max_size = coeffs.size() > other.coeffs.size() ? coeffs.size() : other.coeffs.size();
    std::vector<T> result_coeffs(max_size, T(0));

    for (size_t i = 0; i < max_size; ++i) {
        result_coeffs[i] = (*this)[i] - other[i];
    }

    return Polynomial<T>(result_coeffs);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& other) const {
    size_t result_size = coeffs.size() + other.coeffs.size() - 1;
    std::vector<T> result_coeffs(result_size, T(0));

    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            T product = coeffs[i] * other.coeffs[j];
            result_coeffs[i + j] = result_coeffs[i + j] + product;
        }
    }

    return Polynomial<T>(result_coeffs);
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& other) {
    *this = *this * other;
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Polynomial<U>& poly) {
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        os << poly.coeffs[i] << " ";
    }
    return os;
}

#endif // POLYNOMIAL_TPP