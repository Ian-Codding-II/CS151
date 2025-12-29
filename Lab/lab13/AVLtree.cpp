/**
 * @file AVLtree.cpp
 * @author Ian Codding II
 * @brief AVL binary class implementation
 * @version 0.1
 * @date 2025-11-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "AVLtree.h"
#include "bst.h"

template class AVLtree<double>;

/**
 * @brief returns the height of a tree
 *
 * @param ptr
 * @return int
 */
template<typename T>
 int AVLtree<T>::heightR(TreeNode *ptr) const {
    if (ptr == nullptr) {
        return -1;
    } else {
        return std::max(heightR(ptr->left), heightR(ptr->right)) + 1;
    }
}

/**
 * @brief PREFORMS A LEFT ROTATION
 *
 * @param ptr
 */
template<typename T>
void AVLtree<T>::leftRotate(TreeNodePtr &ptr) {
    // if (mRoot == ptr) {
    //     mRoot = ptr->right;
    // }
    TreeNodePtr temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;
    ptr = temp;
}

/**
 * @brief PREFORMS A RIGHT ROTATION
 *
 * @param ptr
 */
template<typename T>
void AVLtree<T>::rightRotate(TreeNodePtr &ptr) {
    // if (mRoot == ptr) {
    //     mRoot = ptr->left;
    // }
    TreeNodePtr temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;
    ptr = temp;
}

/**
 * @brief The tree is balanced if the absolute value of the difference
 * between left subtrees and right subtrees is no more than 1.
 *
 * @param ptr
 * @return int <--The function should return the height difference between the left and right subtrees.
 */
template<typename T>
int AVLtree<T>::getBalance(TreeNode *ptr) {
    if (ptr == nullptr) {
        return 0;
    }
    return heightR(ptr->left) - heightR(ptr->right);
}

/**
 * @brief INSERSTS WHILE KEEPING THE TREE IN BALANCE.
 *
 * @param ptr
 * @param value
 */
template<typename T>
void AVLtree<T>::insertR(TreeNodePtr &ptr, T value) {
    // Insert node
    BinarySearchTree<T>::insertR(ptr, value);

    // calculate the balance of the node
    int balance = getBalance(ptr);

    // If a node is left heavy and newData was inserted at the left (everything is in one line -> left-left heavy)
    // perform a right rotation
    if (balance > 1 && value < ptr->left->data) {
        rightRotate(ptr);
    }
    // else if a node is right heavy and newData was inserted at the right (everything is in one line -> right-right heavy)
    else if (balance < -1 && value > ptr->right->data) {
        // perform left rotation
        leftRotate(ptr);
    }
    // else if a node is left heavy and newData was inserted at the right (not in one line -> left-right heavy)
    else if (balance > 1 && value > ptr->left->data) {
        // a. make it in one line (left rotation)
        leftRotate(ptr->left);
        // b. perform right rotation
        rightRotate(ptr);
    }
    // else if a node is right heavy and newData was inserted at the left(not in one line-> right-left heavy)
    else if (balance < -1 && value < ptr->right->data) {
        // a. make it in one line (right rotation)
        rightRotate(ptr->right);
        // perform left rotation
        leftRotate(ptr);
    }
}

/**
 * @brief REMOVE WHILE KEEPING THE TREE IN BALANCE.
 *
 * @param ptr
 * @param value
 */
template<typename T>
void AVLtree<T>::removeR(TreeNodePtr &ptr, T value) {
    // Remove Node
    BinarySearchTree<T>::removeR(ptr, value);

    // calculate the balance of the node
    int balance = getBalance(ptr);

    // If a node is left-left heavy.
    // perform a right rotation
    if (balance > 1 && getBalance(ptr->left) <= 0) {
        rightRotate(ptr);
    }

    // else if a node is right-right heavy.
    else if (balance < -1 && getBalance(ptr->right) >=0) {
        // perform left rotation
        leftRotate(ptr);
    }

    // else if a node is left-right heavy
    else if (balance > 1 && getBalance(ptr->left) <= 0) {
        // a. make it in one line (left rotation)
        leftRotate(ptr->left);
        // b. perform right rotation
        rightRotate(ptr);
    }

    // else if a node is right-left heavy
    else if (balance < -1 && getBalance(ptr->right) >= 0) {
        // a. make it in one line (right rotation)
        rightRotate(ptr->right);
        // perform left rotation
        leftRotate(ptr);
    }
}