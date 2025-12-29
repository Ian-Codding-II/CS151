/**
 * @file circularLinkedList.h
 * @author Ian Codding II
 * @brief creation of linked list class
 * @version 0.1
 * @date 2025-10-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include <iostream>
using std::cout;
using std::endl;

// Circular linked list
class CircularLinkedList {
  public:
    CircularLinkedList();         // Constructor
    CircularLinkedList(int data); // Constructor
    ~CircularLinkedList();        // Destructor
    // add one node at the end of class
    void add(int data);
    // display the circular linked list
    void displayList() const;
    // remove the node contain data from the list
    void remove(int data);
    // For part II
    void eatTheDuck(int n);

  private:
  struct Node {
      int value;
      Node *next;
      Node(int value1, Node *next1 = nullptr) {
          value = value1;
          next = next1;
        }
    };
    Node *last;
    int mSize;

    // For part II
    void remove(Node *dptr);
};

#endif // CIRCULARLINKEDLIST_H
