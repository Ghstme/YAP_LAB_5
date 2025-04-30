#include "polynomial.h"
#include <iostream>
#include <windows.h>

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }

    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        double new_real = real * other.real - imag * other.imag;
        double new_imag = real * other.imag + imag * other.real;
        real = new_real;
        imag = new_imag;
        return *this;
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

void demoIntPolynomial() {
    std::cout << "\n=== Демонстрация с целочисленными коэффициентами ===\n";

    Polynomial<int> p1({1, 2, 3}); // 3x^2 + 2x + 1
    Polynomial<int> p2({4, 5});    // 5x + 4

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1 + p2: " << (p1 + p2) << "\n";
    std::cout << "p1 * p2: " << (p1 * p2) << "\n";
    std::cout << "p1(2): " << p1(2) << "\n";
}

void demoComplexPolynomial() {
    std::cout << "\n=== Демонстрация с комплексными коэффициентами ===\n";

    Polynomial<Complex> p1({Complex(1,1), Complex(2,2)}); // (2+2i)x + (1+1i)
    Polynomial<Complex> p2({Complex(3,3)});               // (3+3i)

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1 + p2: " << (p1 + p2) << "\n";
    std::cout << "p1 * p2: " << (p1 * p2) << "\n";
    std::cout << "p1(Complex(1,0)): " << p1(Complex(1,0)) << "\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    demoIntPolynomial();
    demoComplexPolynomial();
    return 0;
}