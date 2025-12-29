/**
 * @file bst.h
 * @author Ian Codding II
 * @brief BinarySearchTree class interface file
 * @date 11/11/25
 * 
 */
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;

template<typename T>
struct TreeNodeT
{
    T data;
    TreeNodeT *left;
    TreeNodeT *right;

    TreeNodeT(T data1=0, TreeNodeT *left1=nullptr, TreeNodeT *right1=nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};
typedef TreeNodeT<int> TreeNode;
typedef TreeNode* TreeNodePtr;

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree(); // DONE
    ~BinarySearchTree();

    // Adding to the tree
    void insert(T newData); // DONE
    void insertR(T newData);

    // Removing an item from the tree
    void removeR(T value); // DONE

    // Searching for an item in the tree
    bool search(T value) const; // DONE
    bool searchR(T value) const;

    // Traversal techniques
    string toStringInOrder() const;
    string toStringInOrderR() const;

    string toStringPreOrderR() const;
    string toStringPostOrderR() const;

    string toStringLevelOrder() const;
    string toStringLevelOrderR() const; // DONE
    int heightR() const; // DONE

    T minValueR() const;
    T maxValueR() const;

    // Changed to protected so inheritance has acsess
protected:
    TreeNode *mRoot;

    // helper functions
    void toStringInOrderR(TreeNode *ptr, ostringstream &ostr) const;
    void toStringLevelOrderR(TreeNode *ptr, ostringstream &ostr, int level) const;

    virtual int heightR(TreeNode *ptr) const;

    bool isLeaf(TreeNode *ptr) const;
    virtual void insertR(TreeNodePtr &ptr, T value);
    virtual void removeR(TreeNodePtr &ptr, T value);
    void deleteNode(TreeNodePtr &nodePtr);
    T processInOrderSuccessor(TreeNodePtr &ptr);

    void destroyTree(TreeNodePtr &ptr);

    bool searchR(TreeNode *ptr, T value) const;

    T minValueR(TreeNode *ptr) const;
    T maxValueR(TreeNode *ptr) const;

    void toStringPreOrderR(TreeNode *ptr, ostringstream &ostr) const;
    void toStringPostOrderR(TreeNode *ptr, ostringstream &ostr) const;
};

#endif
