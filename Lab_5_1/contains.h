#ifndef CONTAINS_H
#define CONTAINS_H

#include <cstddef>

template<typename T>
bool contains(const T &element, const T *array, size_t size);

template<typename T>
void inputArray(T *array, size_t size);

template<typename T>
void demonstrateContains();

#endif // CONTAINS_H
