#include "contains.h"
#include <iostream>
#include <string>

void clearInputBuffer() {
    while (std::cin.get() != '\n') {
        continue;
    }
}

template<typename T>
T getValidInput(const std::string &prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        } else {
            std::cout << "Ошибка ввода! Пожалуйста, введите корректное значение.\n";
            std::cin.clear();
            clearInputBuffer();
        }
    }
    clearInputBuffer();
    return value;
}

template<>
std::string getValidInput<std::string>(const std::string &prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

template<typename T>
bool contains(const T &element, const T *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

template<typename T>
void inputArray(T *array, size_t size) {
    std::cout << "Введите " << size << " элементов массива:\n";
    for (size_t i = 0; i < size; ++i) {
        array[i] = getValidInput<T>("Элемент " + std::to_string(i + 1) + ": ");
    }
}

template<typename T>
void demonstrateContains() {
    size_t size = getValidInput<size_t>("Введите размер массива: ");

    T *array = new T[size];
    inputArray(array, size);

    T element = getValidInput<T>("Введите элемент для поиска: ");

    bool found = contains(element, array, size);
    std::cout << "Элемент " << element << (found ? " найден" : " не найден") << " в массиве.\n\n";

    delete[] array;
}

template bool contains<int>(const int &, const int *, size_t);

template bool contains<double>(const double &, const double *, size_t);

template bool contains<std::string>(const std::string &, const std::string *, size_t);

template void inputArray<int>(int *, size_t);

template void inputArray<double>(double *, size_t);

template void inputArray<std::string>(std::string *, size_t);

template void demonstrateContains<int>();

template void demonstrateContains<double>();

template void demonstrateContains<std::string>();
