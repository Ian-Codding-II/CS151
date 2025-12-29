/**
 * @file AVLtree.h
 * @author Ian Codding II
 * @brief AVL binary tree
 * @version 0.1
 * @date 2025-11-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef AVLTREE_H
#define AVLTREE_H

#include "bst.h"

template<typename T>
class AVLtree : public BinarySearchTree<T> {
  public:
    using BinarySearchTree<T>::heightR;
    using BinarySearchTree<T>::insertR;
    using BinarySearchTree<T>::removeR;

  private:
    int heightR(TreeNode *ptr) const;
    void leftRotate(TreeNodePtr &ptr);
    void rightRotate(TreeNodePtr &ptr);
    int getBalance(TreeNode *ptr);
    void insertR(TreeNodePtr &ptr, T value);
    void removeR(TreeNodePtr & ptr, T value);
};

#endif