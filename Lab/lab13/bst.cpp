/**
 * @file bst.cpp
 * @author Ian Codding II
 * @brief BinarySearchTree class implementation file
 * @date 11/11/25
 *
 */
#include "bst.h"
#include <cstddef>
#include <deque>
#include <queue>
#include <sstream>
#include <stack>

template class BinarySearchTree<double>;

/**
 * @brief Default constructor: Create a Binary Search Tree object
 *
 */
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    // initialize
    mRoot = nullptr;
}

/**
 * @brief Destructor: Destroy the Binary Search Tree
 *
 */
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    // TODO: Stub function for ~BinarySearchTree
    destroyTree(mRoot);
}

/**
 * @brief recursivly desrtoy the tree
 *
 * @param ptr
 */
template<typename T>
void BinarySearchTree<T>::destroyTree(TreeNodePtr &ptr) {
    if (ptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
        // ptr = nullptr;
    }
}

/**
 * @brief Insert node with newData in the Binary Search Tree
 *
 * @param newData value to insert
 */
template<typename T>
void BinarySearchTree<T>::insert(T newData) {
    // case 1: tree is empty
    if (mRoot == nullptr) {
        mRoot = new TreeNode(newData);
    }
    // case 2: not empty
    else {
        TreeNode *prevPtr = nullptr;
        TreeNode *ptr = mRoot;

        while (ptr != nullptr) {
            prevPtr = ptr;
            // data exist
            if (newData == ptr->data) {
                return;
            }
            // go left
            else if (newData < ptr->data) {
                ptr = ptr->left;
            }
            // go right
            else {
                ptr = ptr->right;
            }
        }

        if (newData < prevPtr->data) {
            prevPtr->left = new TreeNode(newData);
        } else {
            prevPtr->right = new TreeNode(newData);
        }
    }
}

/**
 * @brief Insert node with newData in the Binary Search Tree
 *        using recursion
 *
 * @param newData value to insert
 */
template<typename T>
void BinarySearchTree<T>::insertR(T newData) {
    // TODO: Stub function for insertR
    insertR(mRoot, newData);
}

/**
 * @brief Search recursively to insert value in the Binary Search Tree
 *
 * @param ptr
 * @param value
 */
template<typename T>
void BinarySearchTree<T>::insertR(TreeNodePtr &ptr, T value) {
    // TODO: Stub function for insertR
    if (ptr == nullptr) {
        ptr = new TreeNode(value);
    } else if (ptr->data == value) {
        return;
    } else if (ptr->data > value) {
        insertR(ptr->left, value);
    } else {
        insertR(ptr->right, value);
    }
}

/**
 * @brief Travers Binary Search Tree inorder
 *
 * @return string contains in-order traverse of the Binary Search Tree
 */
template<typename T>
string BinarySearchTree<T>::toStringInOrder() const {
    ostringstream ostr("");

    if (mRoot != nullptr) {
        // STEP 1: Create an empty stack S
        std::stack<TreeNodePtr> s;
        // STEP 2: Initialize the current pointer to root
        TreeNodePtr current = mRoot;
        // STEP 3: until current is NULL
        do {
            while (current) {
                // Push the current node to S and set current = current->left
                s.push(current);
                current = current->left;
            }
            // STEP 4: PROCESS the top item,
            //         set current = top_item->right
            ostr << s.top()->data << " ";
            current = s.top()->right;
            // STEP 5: Pop the top item from the stack
            s.pop();
            // STEP 6: If the current is NULL and the stack is empty
            // Then we are done. Otherwise, repeat STEP 3
        } while (current || !s.empty());
    }

    return ostr.str();
}
/**
 * @brief Handle function for recursive toStringInOrdeR function
 *
 * @return string contains in-order traverse of the Binary Search Tree
 */
template<typename T>
string BinarySearchTree<T>::toStringInOrderR() const {
    ostringstream ostr("");
    // TODO: Stub function for toStringInOrderR
    toStringInOrderR(mRoot, ostr);

    return ostr.str();
}
/**
 * @brief Travers Binary Search Tree in-order recursively
 *
 * @return string contains in-order traverse of the Binary Search Tree
 */
template<typename T>
void BinarySearchTree<T>::toStringInOrderR(TreeNode *ptr, ostringstream &ostr) const {
    // TODO: Stub function for toStringInOrderR
    if (ptr == nullptr) {
        return;
    }
    toStringInOrderR(ptr->left, ostr);
    ostr << ptr->data << " ";
    toStringInOrderR(ptr->right, ostr);
}

/**
 * @brief Travers Binary Search Tree Level Order
 *
 * @return string contains level-order traverse of the Binary Search Tree
 */
template<typename T>
string BinarySearchTree<T>::toStringLevelOrder() const {
    ostringstream ostr("");

    if (mRoot != nullptr) {
        // STEP 1: Create an empty queue Q
        std::queue<TreeNodePtr> Q;
        // STEP 2: Enqueue root pointer to Q
        Q.push(mRoot);
        // STEP 3: Loop while Q is not empty
        TreeNodePtr temp;
        while (!Q.empty()) {
            // 3a: Set a temporary pointer to the value at the front of Q
            temp = Q.front();
            // 3b: PROCESS the data pointed by the temporary pointer
            ostr << temp->data << " ";
            // 3c: Dequeue from Q
            Q.pop();
            // 3d: Enqueue the temporary pointer's children to Q as long as they are not NULL
            if (temp->left) {
                Q.push(temp->left);
            }
            if (temp->right) {
                Q.push(temp->right);
            }
        }
    }

    return ostr.str();
}

/**
 * @brief Handle function for recursive toStringLevelOrderR function
 *
 * @return string contains level-order traverse of the Binary Search Tree
 */
template<typename T>
string BinarySearchTree<T>::toStringLevelOrderR() const {
    ostringstream ostr("");

    for (int h = 0; h < heightR(); ++h) {
        toStringLevelOrderR(mRoot, ostr, h);
    }

    return ostr.str();
}

/**
 * @brief Travers Binary Search Tree level Order recursively
 *
 * @return string contains level-order traverse of the Binary Search Tree
 */
template<typename T>
void BinarySearchTree<T>::toStringLevelOrderR(TreeNode *ptr, ostringstream &ostr, int level) const {
    // base case
    if (ptr == nullptr) {
        return;
    } else if (level == 0) {
        ostr << ptr->data << ' ';
        return;
    } else {
        toStringLevelOrderR(ptr->left, ostr, level - 1);
        toStringLevelOrderR(ptr->right, ostr, level - 1);
    }
}

/**
 * @brief Search for value in Binary Search Tree
 *
 * @param value
 * @return true if the value is found
 * @return false if the value is not in the tree
 */
template<typename T>
bool BinarySearchTree<T>::search(T value) const {
    // tree is empty
    if (mRoot == nullptr) {
        return false;
    } else {
        TreeNode *ptr = mRoot;

        while (ptr != nullptr) {
            // found the value
            if (value == ptr->data) {
                return true;
            }
            // go left or go right???
            else if (value > ptr->data) {
                ptr = ptr->right;
            } else {
                ptr = ptr->left;
            }
        }
    }

    return false;
}

/**
 * @brief Handle function for recursive searchR
 *
 * @param value
 * @return true if the value is found
 * @return false if the value is not in the tree
 */
template<typename T>
bool BinarySearchTree<T>::searchR(T value) const {
    // TODO: Stub function for searchR
    return searchR(mRoot, value);
}

/**
 * @brief Recursivly searches the tree
 *
 * @param ptr
 * @param value
 * @return true
 * @return false
 */
template<typename T>
bool BinarySearchTree<T>::searchR(TreeNode *ptr, T value) const {
    if (!ptr) {
        return false;
    } else if (ptr->data == value) {
        return true;
    } else if (value < ptr->data) {
        return searchR(ptr->left, value);
    } else {
        return searchR(ptr->right, value);
    }
}

/**
 * @brief Handle function for recursive  height function
 *
 * @return int
 */
template<typename T>
int BinarySearchTree<T>::heightR() const {
    return heightR(mRoot);
}

/**
 * @brief Finds the height of the tree recursively
 *
 * @param ptr pointer to the root of a subtree
 * @return int height of the tree
 */
template<typename T>
int BinarySearchTree<T>::heightR(TreeNode *ptr) const {
    if (ptr == nullptr) {
        return 0;
    } else {
        return std::max(heightR(ptr->left), heightR(ptr->right)) + 1;
    }
}

/**
 * @brief Handle function for recursive  removeR function
 *
 */
template<typename T>
void BinarySearchTree<T>::removeR(T value) {
    removeR(mRoot, value);
}

/**
 * @brief Search recursively for value in Binary Search Tree
 *          If the value is found, it removes it
 *
 * @param ptr
 * @param value
 */
template<typename T>
void BinarySearchTree<T>::removeR(TreeNodePtr &ptr, T value) {
    // tree is empty
    if (ptr == nullptr) {
        return;
    } else if (value < ptr->data) {
        removeR(ptr->left, value);
    } else if (value > ptr->data) {
        removeR(ptr->right, value);
    } else {
        deleteNode(ptr);
    }
}
/**
 * @brief Delete the node pointed by nodePtr
 *
 * @param nodePtr points to the node to be deleted
 */
template<typename T>
void BinarySearchTree<T>::deleteNode(TreeNodePtr &nodePtr) {
    // 1st case: leaf node
    if (isLeaf(nodePtr)) {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // 2nd case: one child on the left
    else if (nodePtr->right == nullptr) {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->left;
        temp->left = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 2nd case: one child on the right
    else if (nodePtr->left == nullptr) {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->right;
        temp->right = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 3rd case: two children
    else {
        int successorValue = processInOrderSuccessor(nodePtr->right);
        nodePtr->data = successorValue;
    }
}

/**
 * @brief Recursive function that finds the value of a node without left child
 *
 * @param ptr
 * @return int
 */
template<typename T>
T BinarySearchTree<T>::processInOrderSuccessor(TreeNodePtr &ptr) {
    if (ptr->left != nullptr) {
        return processInOrderSuccessor(ptr->left);
    } else {
        int successorValue = ptr->data;

        // leaf node
        if (isLeaf(ptr)) {
            delete ptr;
            ptr = nullptr;
        }
        // right child
        else {
            TreeNode *temp = ptr;
            ptr = ptr->right;
            temp->right = nullptr;
            delete temp;
            temp = nullptr;
        }

        return successorValue;
    }
}

/**
 * @brief Determines if the node is a leaf
 *
 * @param ptr pointer to the node
 * @return true if the node is a leaf
 * @return false if the node is not a leaf
 */
template<typename T>
bool BinarySearchTree<T>::isLeaf(TreeNode *ptr) const {
    return ptr->left == nullptr && ptr->right == nullptr;
}

/**
 * @brief Finds the smallist value in the tree
 *
 * @return int
 */
template<typename T>
T BinarySearchTree<T>::minValueR() const {
    // TODO: Stub function for minValueR
    return minValueR(mRoot);
}

/**
 * @brief Recursivly searches for the smallist
 *
 * @param ptr
 * @return int
 */
template<typename T>
T BinarySearchTree<T>::minValueR(TreeNode *ptr) const {
    // TODO: Stub function for minValueR
    if (!ptr->left) {
        return ptr->data;
    } else {
        return minValueR(ptr->left);
    }
}

/**
 * @brief Finds the biggist value in the tree
 *
 * @return int
 */
template<typename T>
T BinarySearchTree<T>::maxValueR() const {
    // TODO: Stub function for maxValueR
    return maxValueR(mRoot);
}

/**
 * @brief Recursivly finds the biggist value in the tree
 *
 * @param ptr
 * @return int
 */
template<typename T>
T BinarySearchTree<T>::maxValueR(TreeNode *ptr) const {
    // TODO: Stub function for maxValueR
    if (!ptr->right) {
        return ptr->data;
    } else {
        return maxValueR(ptr->right);
    }
}

/**
 * @brief returns preorder of tree
 * 
 * @return string 
 */
template<typename T>
string BinarySearchTree<T>::toStringPreOrderR() const {
    ostringstream ostr("");
    toStringPreOrderR(mRoot, ostr);
    return ostr.str();
}

/**
 * @brief recursivly stores a tree in pre order
 * 
 * @param ptr 
 * @param ostr 
 */
template<typename T>
void BinarySearchTree<T>::toStringPreOrderR(TreeNode *ptr, ostringstream &ostr) const {
    if (ptr) {
        ostr << ptr->data << " ";
        toStringPreOrderR(ptr->left, ostr);
        toStringPreOrderR(ptr->right, ostr);
    }
}

/**
 * @brief returns post order
 * 
 * @return string 
 */
template<typename T>
string BinarySearchTree<T>::toStringPostOrderR() const {
    ostringstream ostr("");
    toStringPostOrderR(mRoot, ostr);
    return ostr.str();
}

/**
 * @brief Recursivly stors a tree in post order
 * 
 * @param ptr 
 * @param ostr 
 */
template<typename T>
void BinarySearchTree<T>::toStringPostOrderR(TreeNode *ptr, ostringstream &ostr) const {
    if (ptr) {
        toStringPostOrderR(ptr->left, ostr);
        toStringPostOrderR(ptr->right, ostr);
        ostr << ptr->data << " ";
    }
}