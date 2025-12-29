/**
 * @file functions.hpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
using namespace std;

const int SIZE = 20;
// function prototypes

void displayArray(int array[], int size);
void displayArrayThroughPointers(int *ptrs[], int size);
void point(int *ptrs[], int array[], int size);
void sortPointers(int *ptrs[], int size);

#endif // FUNCTIONS_HPP
