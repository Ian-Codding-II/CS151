/**
 * @file Vector.h
 * @author Ian Codding II
 * @brief 
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using std::cout, std::cin, std::endl;

class Vector
{
public:
    // Default constructor to initialize
    // an initial capacity of 1 element and
    // allocating storage using dynamic allocation
    Vector();
    // Constructor that initializes mCapacity and mSize two size,
    // allocating storage using dynamic allocation, and
    // sets all elements to 0
    Vector(int size);
    int size() const;
    int capacity() const;
    // Adds an element to the end
    void push_back(int n);
    void pop_back();
    //Return the reference to the vector element
    //specified by index
    int& operator[](int index);
    //Display vector, its capacity and size
    virtual void print() const;
    // Free/release any dynamic memory
    ~Vector();

protected:
    int *mElements;
    int mSize;
    int mCapacity;
};

#endif // VECTOR_H
