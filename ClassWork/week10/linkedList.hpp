/**
 * @file linkedList.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <iostream>
#include <sstream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

/**
 * @brief LinkedList class
 *
 */
class LinkedList {
  public:
    LinkedList();
    // default constructor
    ~LinkedList();
    // destructor
    void add(double number);
    void remove(double number);
    string toString() const;
    string toStringR() const;
    // recursive
    unsigned int size() const;
    unsigned int sizeR() const;
    // recursive
  protected:
    struct Node {
        int value;
        Node *next;
        Node(int d = 0, Node *p = nullptr) {
            value = d;
            next = p;
        }
    };
    Node *mHead;
    // list head pointer
    unsigned int mSize;
    // size of the list
  private:
    // helper functions
    unsigned int sizeR(Node *ptr) const;
    string toStringR(Node *ptr) const;
};