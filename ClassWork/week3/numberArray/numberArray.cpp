#include "numberArray.h"
#include <cstddef>

NumberArray::NumberArray(int size, double initValue) {
    if (size < 0) {
        std::cerr << "Size of number array can't be nagative\n";
        exit(1);
    }
    arraySize = size;
    arr = new double[size];
    if (arr == nullptr) {
        std::cerr << "Can't creat object\n";
        exit(1);
    }
    for (int i = 0; i < arraySize; i++) {
        arr[i] = initValue;
    }
}

NumberArray::NumberArray(const NumberArray &t) {
    arraySize = t.arraySize;
    arr = new double[arraySize];
    if (arr == nullptr) {
        std::cerr << "Can't creat object\n";
        exit(1);
    }
    for (int i = 0; i < arraySize; i++) {
        arr[i] = (t.arr)[i];
    }
}

void NumberArray::print() const {
    if (arraySize == 0) {
        std::cout << "Array is empty\n";
    } else {
        std::cout << "Size of array: " << arraySize << std::endl;
        for (int i = 0; i < arraySize; i++) {
            std::cout << "Array element: " << arr[i] << std::endl;
        }
    }
}

void NumberArray::setValue(double value) {
    *arr = value;
}