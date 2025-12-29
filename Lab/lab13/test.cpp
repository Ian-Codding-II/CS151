/**
 * @file test.cpp
 * @author Ian Codding II
 * @brief Test the binary search tree implementation
 * @date 11/11/25
 * 
 */
// #include <iostream>
// #include "bst.h"

// using std::cout;

// int main()
// {
//     BinarySearchTree myTree;

//     // Draw BST 
//     myTree.insertR(50);
//     myTree.insertR(30);
//     myTree.insertR(70);
//     myTree.insertR(40);
//     myTree.insertR(20);
//     myTree.insertR(25);
//     myTree.insertR(60);
//     myTree.insertR(75);
//     myTree.insertR(80);
    
//     cout << "In order: " << myTree.toStringInOrderR() << '\n';
//     cout << "In order: " << myTree.toStringInOrder() << '\n';
    
//     cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
//     cout << "Level order: " << myTree.toStringLevelOrderR() << '\n';

//     cout << "search for 85: " << myTree.search(85) << '\n';
//     cout << "searchR for 85: " << myTree.searchR(85) << '\n';
//     cout << "search for 25: " << myTree.search(25) << '\n';
//     cout << "searchR for 25: " << myTree.searchR(25) << '\n';

//     cout << "the max value in the tree: " << myTree.maxValueR() << '\n';
//     cout << "the min value in the tree: " << myTree.minValueR() << '\n';

//     myTree.removeR(20);
//     myTree.removeR(55);
//     myTree.removeR(50);
//     myTree.removeR(70);

//     cout << "In order: " << myTree.toStringInOrderR() << '\n';
//     cout << "In order: " << myTree.toStringInOrder() << '\n';

//     cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
//     cout << "Level order: " << myTree.toStringLevelOrderR() << '\n';

//     return 0;
// }

#include <iostream>
#include "AVLtree.h"
#include "bst.h"

using std::cout;

int main()
{
    AVLtree<double> myTree;

    // Draw BST
    cout<< "Insert 10\n";
    myTree.insertR(10);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 12\n";
    myTree.insertR(12);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 15\n";
    myTree.insertR(15);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 20\n";
    myTree.insertR(20);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 16\n";
    myTree.insertR(16);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 13\n";
    myTree.insertR(13);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 7\n";
    myTree.insertR(7);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 3\n";
    myTree.insertR(3);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';
    cout<< "Insert 9\n";
    myTree.insertR(9);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';

    cout<<"Removing 13...\n";
    myTree.removeR(13);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';

    cout<<"Removing 10...\n";
    myTree.removeR(10);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';

    cout<<"Removing 7...\n";
    myTree.removeR(7);
    cout <<"The height of the tree is "<<myTree.heightR()<<'\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';
    cout << "In-order: " << myTree.toStringInOrderR() << '\n';
    cout << "Pre-order: " << myTree.toStringPreOrderR() << '\n';
    cout << "Post-order: " << myTree.toStringPostOrderR() << '\n';

    return 0;

}