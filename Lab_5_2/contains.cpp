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
bool change(const T &elem1, const T &elem2, T *array, size_t size) {
    if (!contains(elem1, array, size) || !contains(elem2, array, size)) {
        std::cout << "Ошибка: один или оба элемента отсутствуют в массиве!\n";
        return false;
    }

    size_t index1 = -1, index2 = -1;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == elem1) index1 = i;
        if (array[i] == elem2) index2 = i;
        if (index1 != -1 && index2 != -1) break;
    }

    std::swap(array[index1], array[index2]);
    std::cout << "Элементы успешно поменялись местами!\n";
    return true;
}

template<typename T>
void inputArray(T *array, size_t size) {
    std::cout << "Введите " << size << " элементов массива:\n";
    for (size_t i = 0; i < size; ++i) {
        array[i] = getValidInput<T>("Элемент " + std::to_string(i + 1) + ": ");
    }
}

template<typename T>
void demonstrateChange() {
    size_t size = getValidInput<size_t>("Введите размер массива: ");

    T *array = new T[size];
    inputArray(array, size);

    std::cout << "Введите первый элемент для обмена: ";
    T elem1 = getValidInput<T>("");
    std::cout << "Введите второй элемент для обмена: ";
    T elem2 = getValidInput<T>("");

    bool success = change(elem1, elem2, array, size);

    if (success) {
        std::cout << "Массив после обмена:\n";
        for (size_t i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }

    delete[] array;
}

template bool contains<int>(const int &, const int *, size_t);

template bool contains<double>(const double &, const double *, size_t);

template bool contains<std::string>(const std::string &, const std::string *, size_t);

template bool change<int>(const int &, const int &, int *, size_t);

template bool change<double>(const double &, const double &, double *, size_t);

template bool change<std::string>(const std::string &, const std::string &, std::string *, size_t);

template void inputArray<int>(int *, size_t);

template void inputArray<double>(double *, size_t);

template void inputArray<std::string>(std::string *, size_t);

template void demonstrateChange<int>();

template void demonstrateChange<double>();

template void demonstrateChange<std::string>();
