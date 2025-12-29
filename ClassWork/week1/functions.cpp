/**
 * @file functions.cpp
 * @author Ian Codding II
 * @brief Defineing functions,
 * @version 0.1
 * @date 2025-08-20
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "functions.hpp"

/**
 * @brief Prints to the screen.
 *
 * @param c
 */
void printCarInfo(Car c) {
  std::cout << "Model:" << c.model << " \n";
  std::cout << "Color:" << c.color << " \n";
  std::cout << "Make:" << c.make << " \n";
}

/**
 * @brief Search array of cars for there brand.
 *
 * @param cars array of cars
 * @param maker brand to search for
 * @return int index of the firstcar with specified maker of
 *     -1 if car not found
 */
int searchMaker(Car cars[], int size, std::string maker) {
  for (int i = 0; i < size; i++) {
    if (cars[i].make == maker) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief sorts the array with binary algorythem.
 *
 * @param array
 * @param size
 * @param value
 * @return int
 */
int binarySearch(const Car array[], int size, int value) {
  int first = 0,       // First array element
      last = size - 1, // Last array element
      middle,          // Midpoint of search
      position = -1;   // Position of search value
  bool found = false;  // Flag
  while (!found && first <= last) {
    middle = (first + last) / 2;      // Calculate midpoint
    if (array[middle].model == value) // If value is found at mid
    {
      found = true;
      position = middle;
    } else if (array[middle].model > value) // If value is in lower half
    {
      last = middle - 1;
    } else {
      first = middle + 1; // If value is in upper half
    }
  }
  return position;
}

/**
 * @brief bubble sort.
 *
 * @param array
 * @param size
 */
void sortArray(Car array[], int size) {
  bool madeAswap = true;
  int lastIndex = size - 1;
  while (madeAswap) {
    madeAswap = false;
    for (int count = 0; count < lastIndex; ++count) {
      if (array[count].model > array[count + 1].model) {
        Car temp = array[count];
        array[count] = array[count + 1];
        array[count + 1] = temp;
        madeAswap = true;
      }
    }
    --lastIndex;
  }
}

/**
 * @brief
 *
 * @param array
 * @param size
 */
void selectionSort(Car array[], int size) {
  for (int startScan = 0; startScan < (size - 1); ++startScan) {
    int minIndex = startScan;
    int minValue = array[startScan].model;
    for (int index = startScan + 1; index < size; ++index) {
      if (array[index].model < minValue) {
        minValue = array[index].model;
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan].model = minValue;
  }
}

/**
 * @brief
 *
 * @param array
 * @param size
 */
void insertionSort(Car array[], int size) {
  for (int startScan = 1; startScan < size; ++startScan) {
    Car key = array[startScan];
    int index = startScan - 1;
    while (index >= 0 && array[index].model > key.model) {
      array[index + 1] = array[index];
      --index;
    }
    array[index + 1] = key;
  }
}