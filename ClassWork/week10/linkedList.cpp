/**
 * @file linkedList.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "linkedList.hpp"

LinkedList::LinkedList() {
    mHead = nullptr;
    mSize = 0;
}
// default constructor

LinkedList::~LinkedList() {
    while (mHead != nullptr) { // keep track of node to be deleted
        Node *nodeToDelete = mHead;
        // Move on to the next node, if any
        mHead = mHead->next;
        // Fully isolate the node to be deleted
        nodeToDelete->next = nullptr;
        // Delete the node
        delete nodeToDelete;
    }
}
// destructor

void LinkedList::add(double number) {
    mHead = new Node(number, mHead);
    mSize++;
}

string LinkedList::toString() const {
    Node *nodePtr = mHead;
    std::ostringstream ostr;
    while (nodePtr) { // Print the value in the current node
        ostr << nodePtr->value << ' ';
        // Move on to the next node
        nodePtr = nodePtr->next;
    }
    return ostr.str();
}

string LinkedList::toStringR() const {
}
// recursive
string LinkedList::toStringR(Node *ptr) const {
}

unsigned int LinkedList::size() const {
    return mSize;
}

unsigned int LinkedList::sizeR() const {
}

unsigned int LinkedList::sizeR(Node *ptr) const {
}

void LinkedList::remove(double number) {
    // If the list is empty, do nothing
    if (!mHead)
        return;
    // Determine if the first node is the one to delete
    if (mHead->value == number) {
        Node *nodePtr = mHead;
        mHead = mHead->next;
        nodePtr->next = nullptr;
        delete nodePtr;
        nodePtr = nullptr;
    } else {
        Node *previousNodePtr = mHead;
        Node *nodePtr = mHead->next;
        // Skip nodes whose value member is not the number
        while (nodePtr != nullptr && nodePtr->value != number) {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Link the previous node to the node after nodePtr,
        // then delete nodePtr
        if (nodePtr) {
            previousNodePtr->next = nodePtr->next;
            nodePtr->next = nullptr;
            delete nodePtr;
            nodePtr = nullptr;
        }
    }
}