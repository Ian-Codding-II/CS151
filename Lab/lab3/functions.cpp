/**
 * @file functions.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "functions.hpp"
/**
 * @brief Display integer array
 *
 * @param array integer array
 * @param size array size
 */
void displayArray(int array[], int size) {

    cout << "The original array is:\n";
    // DISPLAT AN ARRAY
    for (int i = 0; i < size; i++) {

        cout << array[i];
        if (i + 1 != size) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * @brief Initialize each pointer in an array of pointers ptrs
 *        with the address of the corresponding element in the array
 *
 * @param ptrs array of pointers to int
 * @param array array of integers
 * @param size size of each array
 */

void point(int *ptrs[], int array[], int size) {
    // ASSIGN EACH POINTER IN ptrs THE ADRESS OF CORRESPONDING ELEMENT IN array
    for (int i = 0; i < size; i++) {
        ptrs[i] = &array[i];
    }
}

/**
 * @brief Indirectly display an array of integers using pointers
 *
 * @param ptrs array of pointers to int
 * @param size size of the array
 */

void displayArrayThroughPointers(int *ptrs[], int size) {
    cout << "The given array through pointers is:\n";
    // DISPLAY array USING POINTERS IN ptrs
    for (int i = 0; i < size; i++) {
        cout << *ptrs[i];
        if (i + 1 != size) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * @brief Indirectly sort the array of pointers
 *
 * @param ptrs array of pointers to int
 * @param size size of the array
 */

void sortPointers(int *ptrs[], int size) {

    // USE ANY SORTING ALGORITHM AND SORT THE ARRAY OF POINTERS ptrs
    // BASED ON VALUES THEY POINT
    // NOTE: THE ORIGINAL ARRAY OF INT MUST STAY UNCHANGED
    bool madeAswap = true;
    int lastIndex = size - 1;
    while (madeAswap) {
        madeAswap = false;
        for (int count = 0; count < lastIndex; ++count) {
            if (*ptrs[count] > *ptrs[count + 1]) {
                int *temp = ptrs[count];
                ptrs[count] = ptrs[count + 1];
                ptrs[count + 1] = temp;
                madeAswap = true;
            }
        }
        --lastIndex;
    }
}
