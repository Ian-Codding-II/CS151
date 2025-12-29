/**
 * @file circularLinkedList.cpp
 * @author Ian Codding II
 * @brief Implementaion of my linked list class
 * @version 0.1
 * @date 2025-10-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "circularLinkedList.h"
#include <cstddef>

/**
 * @brief Construct a new Circular Linked List:: Circular Linked List object
 *
 */
CircularLinkedList::CircularLinkedList() {
    last = nullptr;
    mSize = 0;
}
/**
 * @brief Construct a new Circular Linked List:: Circular Linked List object
 *
 * @param data
 */
CircularLinkedList::CircularLinkedList(int data) {
    // Constructor that accepts int value
    // It dynamically allocates memory for the node and stores the int value in it
    last = new Node(data);
    // A successor pointer of the node should be pointed to the node itself (creates a circular linked list with one node)
    last->next = last;
    // Sets the mSize to the correct value
    mSize = 1;
}
/**
 * @brief Destroy the Circular Linked List:: Circular Linked List object
 *
 */
CircularLinkedList::~CircularLinkedList() {
    // If the circular linked list has any nodes,
    // traverse the list and remove each node (deallocate the memory)
    if (mSize != 0) {
        Node *temp = last; // Disconnect list
        last = last->next;
        temp->next = nullptr;

        while (last != temp) { // keep track of node to be deleted
            Node *nodeToDelete = last;
            // Move on to the next node, if any
            last = last->next;
            // Fully isolate the node to be deleted
            nodeToDelete->next = nullptr;
            // Delete the node
            delete nodeToDelete;
        }
        delete temp;
    }
}

/**
 * @brief // add one node at the end of class

 *
 * @param data
 */
void CircularLinkedList::add(int data) {
    // If the circular linked list is empty, act as a constructor
    if (mSize == 0) {
        last = new Node(data);
        last->next = last;
        mSize = 1;
    } else { // If the circular linked list is not empty:
        // dynamically allocate the memory for a new node, using data for value
        Node *temp = new Node(data);
        // point its successor pointer to the first node in the linked list
        temp->next = last->next;
        // point the successor pointer of the previous node to the new node
        last->next = temp;
        // make the new node the last node
        last = temp;
        // update mSize
        mSize++;
    }
    // last->next = new Node(data, last->next);
    // last = last->next;
    // mSize++;
}

/**
 * @brief display the circular linked list
 *
 */
void CircularLinkedList::displayList() const {
    if (mSize == 0) {
        cout << "List is empty\n";
    } else {
        Node *ptr = last->next; // point to the first value
        for (int i = 0; i < mSize; i++) {
            cout << ptr->value << " ";
            ptr = ptr->next; // assign to the next ptr
        }
    }
}
/**
 * @brief remove the node contain data from the list
 *
 * @param data
 */
void CircularLinkedList::remove(int data) {
    Node *temp = last;
    for (int i = 0; i < mSize; i++) {
        if (temp->next->value != data) {
            temp = temp->next;
        } else {
            if (temp->next == last) { // if we delete only the last then we need reasign.
                last = temp;
            }
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            mSize--;
        }
    }
}

/**
 * @brief For part II
 * This function counts nods (ducks) starting with the first one and eats every nth.
 * Eaten duck gets removed from the list
 *
 * @param n
 */
void CircularLinkedList::eatTheDuck(int n) {
    if (n < 1 || mSize == 0) { // check if we shouldn't display.
        return;
    }
    cout << "Ducks in the circle: ";
    displayList();
    cout << endl;

    Node *current = last->next; // Start counting from the first duck

    while (mSize > 0) { // while there is still ducks to be eaten.
        // Find the duck to eat by counting n from current
        Node *to_eat = current;
        for (int i = 1; i < n; ++i) {
            to_eat = to_eat->next;
        }
        // Find the previous node to to_eat
        Node *prev = to_eat;
        while (prev->next != to_eat) {
            prev = prev->next;
        }

        int duck_num = to_eat->value;
        cout << "Duck " << duck_num << " is eaten\n";

        // Set current to the next after to_eat before removal
        current = to_eat->next;

        // Remove the duck
        remove(prev);

        // Print the remaining ducks
        cout << "The ducks left are: ";
        if (mSize == 0) {
            cout << "List is empty\n";
        } else {
            displayList();
            cout << endl;
        }
    }
}

/**
 * @brief For part II
 * This function removes the next node after the node pointed by dptr.
 * Could have made this function without usig previous ptr.
 *
 * @param dptr
 */
void CircularLinkedList::remove(Node *dptr) {
    Node *tempToDelete = dptr->next; // next
    if (mSize == 1) { // Eat the duck function will work without this check
                    //  because I check it there. Leaving it here because it feels right
        delete tempToDelete;
        last = nullptr;
        mSize = 0;
    } else {
        if (tempToDelete == last) {
            last = dptr; // this is asigning to the one before it.
        }
        dptr->next = dptr->next->next; // close gap
        delete tempToDelete;
        mSize--;
    }
}
