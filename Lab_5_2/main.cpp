#include "contains.h"
#include <string>
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== Демонстрация функции change ===\n";

    std::cout << "\n=== Для типа int ===\n";
    demonstrateChange<int>();

    std::cout << "\n=== Для типа double ===\n";
    demonstrateChange<double>();

    std::cout << "\n=== Для типа std::string ===\n";
    demonstrateChange<std::string>();

    return 0;
}
