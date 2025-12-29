/**
 * @file Vector.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Vector.h"
#include <cstddef>
/**
 * @brief Construct a new Vector:: Vector object
 *  Vector will have an initial capacity of 1
 *  Assign a dynamic array with a size of 1 to mElements
 *  What should be the initial values of mCapacity and mSize?
 *
 */
Vector::Vector() {
    cout << "Parent is created...\n";

    mCapacity = 1;
    mElements = new int[mCapacity];
    mSize = 0;
}
/**
 * @brief Construct a new Vector:: Vector object
 *  Vector will have mCapacity and mSize = size
 *  Assign a dynamic array with a size of mSize to mElements
 *  Assign value 0 to all elements
 *
 * @param size
 */
Vector::Vector(int size) {
    cout << "Parent with size is created...\n";

    if (size <= 0) {
        size = 0;
        mCapacity = 1;
    } else {
        mSize = size;
        mCapacity = size;
    }
    mElements = new int[mCapacity];
    for (int i = 0; i < size; i++) {
        mElements[i] = 0;
    }
}

/**
 * @brief Destroy the Vector:: Vector object
 *  Free or release the dynamic array
 *
 */
Vector::~Vector() {
    cout << "Parent is destroyed...\n";

    delete[] mElements;
}

/**
 * @brief //  Display vector, its capacity and size. See the example of the output.
 *
 */
void Vector::print() const {
    for (int i = 0; i < mSize; i++) {
        cout << mElements[i] << " ";
    }
    cout << endl;
    cout << "Vector size is " << mSize << endl;
    cout << "Vector capacity is " << mCapacity << endl;
}

/**
 * @brief If the number of elements (mSize) is equal to the capacity,
 * which means we don’t have enough space to accommodate more elements,
 * thus before we can add, you need to increase the capacity of the vector (mElements)
 *
 * @param data
 */
void Vector::push_back(int data) {
    if (mSize == mCapacity) {
        // Simply double the capacity
        mCapacity *= 2;
        // Create a temporary pointer variable pointing to a
        // dynamically allocated array with double the current capacity
        int *temp = new int[mCapacity];
        // Copy the existing elements in the vector into the newly created temporary array
        for (int i = 0; i < mSize; i++) {
            temp[i] = mElements[i];
        }
        // Free the memory of the previous or old array
        delete[] mElements;
        // Assign the temporary array as the new vector
        mElements = temp;
    }
    // Add data at the end of the vector
    mElements[mSize] = data;
    // Increment mSize
    mSize++;
}

/**
 * @brief Clue on the implementation of this function:
 * You only need one very short statement updating one of the member variables
 * You do not need to resize the dynamic array
 * Make sure there are elements in the vector
 *
 */
void Vector::pop_back() {
    if (mSize > 0) {
        mSize--;
    }
}

/**
 * @brief Return the current size of the vector
 *
 * @return int
 */
int Vector::size() const {
    return mSize;
}
/**
 * @brief Return the current capacity of the vector
 *
 */
int Vector::capacity() const {
    return mCapacity;
}
/**
 * @brief Return the reference to the vector element specified by the index
 * Check if the index is valid
 *
 */
int &Vector::operator[](int index) {
    if (index >= 0 && index < mSize) {
        return mElements[index];
    } else {
        return mElements[0];
    }
}
