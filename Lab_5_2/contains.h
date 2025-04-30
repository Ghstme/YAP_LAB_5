#ifndef CONTAINS_H
#define CONTAINS_H

#include <cstddef>

template<typename T>
bool contains(const T &element, const T *array, size_t size);

template<typename T>
void inputArray(T *array, size_t size);

template<typename T>
void demonstrateContains();

template<typename T>
bool change(const T &elem1, const T &elem2, T *array, size_t size);

template<typename T>
void demonstrateChange();

#endif // CONTAINS_H
