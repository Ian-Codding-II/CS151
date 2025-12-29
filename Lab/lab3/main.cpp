/**
 * @file   lab2.cpp
 * @author Ian Codding II
 * @brief  This program demonstrates indirectly sorting using pointers.
 * @date   WRITE DATE TODAY
 *
 */
#include "functions.hpp"
#include <iostream>
using namespace std;

int main() {
    // initialize the array of integers
    int numbers[SIZE] = {1, 34, 5, 78, 34, 6, 4, 90, 11, 23,
                         45, 8, 9, 13, 24, 87, 33, 44, 10, 27};

    displayArray(numbers, SIZE);

    // DEFINE THE ARRAY OF POINTERS CALLED ptr
    int *ptr[SIZE];

    // point each element of prt to the corresponding element in numbers
    point(ptr, numbers, SIZE);

    // display numbers array using ptr
    displayArrayThroughPointers(ptr, SIZE);

    cout << "Sorting the array indirectly...\n";

    // sort pointers in ascending order
    sortPointers(ptr, SIZE);

    // display numbers array using ptr. It should be sorted
    displayArrayThroughPointers(ptr, SIZE);

    // display number array
    displayArray(numbers, SIZE);

    return 0;
}
