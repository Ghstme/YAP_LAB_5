#include "matrix_demo.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    do {
        std::cout << "\nВыберите демонстрацию:\n"
                << "1. Целочисленные матрицы\n"
                << "2. Вещественные матрицы\n"
                << "3. Строковые матрицы\n"
                << "4. Выход\n"
                << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: demoIntMatrix();
                break;
            case 2: demoDoubleMatrix();
                break;
            case 3: demoStringMatrix();
                break;
            case 4: std::cout << "Выход из программы.\n";
                break;
            default: std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}
