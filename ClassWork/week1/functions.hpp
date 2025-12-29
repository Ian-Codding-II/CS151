#ifndef function_hpp
#define function_hpp

#include "car.hpp"
#include <iostream>

void printCarInfo(Car c);
int searchMaker(Car cars[], int size, std::string maker);
int binarySearch(const Car array[], int size, int value);
void sortArray(Car array[], int size);
void selectionSort(Car array[], int size);
void insertionSort(Car array[], int size);

const int size = 3;

#endif