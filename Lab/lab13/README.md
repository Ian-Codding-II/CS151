# Lab 13: Binary Search Tree

### Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Implement a binary search tree
* Implement the operations in binary search tree using recursion or iteration
* Use stacks and queues in converting recursive functions into iterative functions

## Implement a Binary Search Tree (BST) class

> **IMPORTANT**: You are not allowed to use the Internet for this lab or the book. You should also not look at the lecture code. You can use the lecture notes or your own notes)

### Pre-Task
- [ ] Open Visual Studio Code
- [ ] Open **test.cpp**, **bst.h**, and **bst.cpp**. These files contain a similar code demonstrated during our lecture. Some of the class member functions you will have to reimplement, while other binary search tree operations needs to be implemented using a different approach.
- [ ] Go over the `insert()` calls in **test.cpp** and draw the binary search tree in the paper provided.
- [ ] Write on the paper what is the sequence of each node value visited when traversing by:
    - [ ] In-order Traversal
    - [ ] Pre-order Traversal
    - [ ] Post-order Traversal
    - [ ] Level-order Traversal
- [ ] **IMPORTANT NOTE**: The member functions you need to implement in each task below already has a function defined in **bst.cpp**. However, if needed, create a helper function. Go over each task sequentially. Start with **Task 1**.

### Task 1
- [ ] Go over the code in **bst.h** so you are familiar with the `struct TreeNode` and the class member variables in `class BinarySearchTree`.
- [ ] During our lecture, we implemented `insert()` which uses an ***iterative method*** of adding new nodes in the BST. Your task is to implement `insertR()` that inserts a node using ***recursion***. Create a helper function as needed.
    > The implementation of `insert()` is available in **bst.cpp** for reference
- [ ] Once completed, replace all call to the `insert()` to `insertR()` in **test.cpp**.
- [ ] Implement `toStringInOrderR()` that writes to a string stream the contents of the BST in order ***using recursion***. Contents will be separated by a single space. This function returns the contents as a string.
- [ ] Compile and execute to test `insertR()` and `toStringInOrderR()` in **test.cpp**.
- [ ] Commit your code to Github

### Task 2
- [ ] Implement `toStringInOrder()` that writes to a string stream the contents of the BST in order ***iteratively***. You will have to use a **stack** to do this. Look for the function definition of `toStringInOrder()` in **bst.cpp**. A psuedocode has been provided as comments inside the function.
- [ ] Draw a stack in a paper. Draw the changes to the stack as you walk through each step in the pseudocode as you traverse the binary search tree.
- [ ] Uncomment the lines in **test.cpp** that uses this function you implemented and test your code
- [ ] Commit your code to Github

### Task 3
- [ ] Implement the destructor, `~BinarySearchTree()`. Create a helper function called `destroyTree()` and implement this function recursively.
- [ ] Once completed, check that there are no memory leaks.
 ````bash
 sudo apt install valgrind
 g++ -Wall -g *.cpp
 valgrind --leak-check=full ./a.out
 ````
- [ ] Commit your code to Github.

### Task 4
- [ ] Implement `searchR()` that searches BST for a value recursively. Return `true` if value exists, otherwise, return `false`.
- [ ] Uncomment the lines in **test.cpp** that uses this function you implemented and test your code.
- [ ] Commit your code to Github.

### Task 5
- [ ] Create two additional member functions:
    - [ ] `minValueR()` is a function that returns the minimum value found in the tree. Use recursion in your implementation.
    - [ ] `maxValueR()` is a function that returns the maximum value found in the tree. Use recursion in your implementation.
- [ ] Uncomment the lines in **test.cpp** that uses the functions you implemented and test your code
- [ ] Commit your code to Github

### Task 6
- [ ] Implement `toStringLevelOrder()` that writes to a string stream the contents of the BST in order ***iteratively***. You will have to use a **queue** to do this. Look for the function definition of `toStringLevelOrder()` in **bst.cpp**. A psuedocode has been provided as comments inside the function.
- [ ] Draw a queue in a paper. Draw the changes to the queue as you walk through each step in the pseudocode as you traverse the binary search tree.
- [ ] Uncomment the lines in **test.cpp** that uses this function you implemented and test your code
- [ ] Commit your code to Github
- [ ] Push your code to Github

## Submitting Lab Assignments
- [ ] It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.
