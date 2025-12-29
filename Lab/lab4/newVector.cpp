/**
 * @file newVector.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "newVector.h"
/**
 * @brief fills the whole array with a desired input
 *
 * @param fill
 */
void newVector::doSomthing(int fill) {
    for (int i = 0; i < mSize; i++) {
        mElements[i] = fill;
    }
}
/**
 * @brief display
 *
 */
void newVector::print() const {
    cout << "Vector: ";
    for (int i = 0; i < mSize; i++) {
        cout << mElements[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Destroy the new Vector::new Vector object
 *
 */
newVector::~newVector() {
    cout << "Child is destroyed...\n";
}
/**
 * @brief Construct a new new Vector::new Vector object
 *
 * @param size
 */
newVector::newVector(int size)
    : Vector(size) {
    cout << "Child with size is created...\n";
}
/**
 * @brief Construct a new new Vector::new Vector object
 * 
 */
newVector::newVector() {
    cout << "Child is created...\n";
}