#include "contains.h"
#include <string>
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== Проверка наличия элемента в массиве ===\n";

    std::cout << "\n=== Демонстрация для типа int ===\n";
    demonstrateContains<int>();

    std::cout << "\n=== Демонстрация для типа double ===\n";
    demonstrateContains<double>();

    std::cout << "\n=== Демонстрация для типа std::string ===\n";
    demonstrateContains<std::string>();

    return 0;
}
