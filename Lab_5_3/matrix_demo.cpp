#include "matrix.h"
#include "matrix_demo.h"
#include <iostream>
#include <string>

void clearInputBuffer() {
    int c;
    while ((c = std::cin.get()) != '\n' && c != EOF) {
    }
}

void demoIntMatrix() {
    std::cout << "\n=== Демонстрация работы с целочисленной матрицой ===\n";

    Matrix<int> m1(2, 2);
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix<int> m2(2, 2);
    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    std::cout << "Матрица 1:\n" << m1;
    std::cout << "Матрица 2:\n" << m2;

    std::cout << "Сумма матриц:\n" << (m1 + m2);

    Matrix<int> m3(2, 3);
    std::cout << "Введите элементы матрицы 2x3:\n";
    std::cin >> m3;
    std::cout << "Введенная матрица:\n" << m3;
}

void demoDoubleMatrix() {
    std::cout << "\n=== Демонстрация работы с матрицей вещественных чисел ===\n";

    Matrix<double> m1 = {{1.1, 2.2}, {3.3, 4.4}};
    Matrix<double> m2 = {{5.5, 6.6}, {7.7, 8.8}};

    std::cout << "Матрица 1:\n" << m1;
    std::cout << "Матрица 2:\n" << m2;

    std::cout << "Произведение матриц:\n" << (m1 * m2);
}

void demoStringMatrix() {
    std::cout << "\n=== Демонстрация работы со строковой матрицей ===\n";

    Matrix<std::string> m1(2, 2);
    m1.set(0, 0, "Hello");
    m1.set(0, 1, "World");
    m1.set(1, 0, "C++");
    m1.set(1, 1, "Matrix");

    Matrix<std::string> m2(2, 2);
    m2.set(0, 0, "Good");
    m2.set(0, 1, "Bye");
    m2.set(1, 0, "Happy");
    m2.set(1, 1, "Coding");

    std::cout << "Матрица 1:\n" << m1;
    std::cout << "Матрица 2:\n" << m2;

    std::cout << "Сумма строковых матриц (конкатенация):\n" << (m1 + m2);
}
