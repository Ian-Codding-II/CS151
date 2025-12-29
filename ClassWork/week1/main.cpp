/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "car.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
  Car toy[size] = {
      {"Mazda", 2014, "silver"}, {"truck", 2025, "blue"}, {"hunda", 2000, "black"}};
  // toy[0].color="blue";
  // toy[0].model=2000;
  // toy[0].make="Mazda";

  // std::cout << "Hello World\n";
  for (int i = 0; i < 3; i++) {
    printCarInfo(toy[i]);
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // int index = searchMaker(toy, size, "mazda");
  // if (index <= -1) {
  //   std::cout << "Brand not found\n";
  // } else {
  //   printCarInfo(toy[index]);
  // }

  insertionSort(toy, size);
  // binarySearch(toy,size, 3);
  for (int i = 0; i < 3; i++) {
    printCarInfo(toy[i]);
    std::cout << std::endl;
  }

  return 0;
}