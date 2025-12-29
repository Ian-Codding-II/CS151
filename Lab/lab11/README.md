# Lab11: Circular Linked List
## Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Create and use pointers to create dynamic memory in C++
* Create a circular linked list
* Solve the "Duck" problem using a circular link list
* Test for memory leaks

## Lab 11.1: Implement Circular Linked List
* `main.cpp` and `circulaLinkedList.h` files are given.
* Create `circularLinkedList.cpp` file and implement the functions. Test your implementation using part I in `main.cpp`.
### Implementation details for each of the member functions of the LinkedList class
- [ ] `CircularLinkedList()`
 * Set the values for last and `mSize`
 
- [ ] `CircularLinkedList(int data)`
 * Constructor that accepts int value
* It dynamically allocates memory for the node and stores the int value in it
* A successor pointer of the node should be pointed to the node itself (creates a circular linked list with one node)
* Sets the `mSize` to the correct value

- [ ] `~CircularLinkedList()`
 * If the circular linked list has any nodes, traverse the list and remove each node (deallocate the memory)
 
- [ ] `void displayList() const`
* If the circular linked list has any nodes, display each node starting with the first

- [ ] `void add(int data)`
 * If the circular linked list is empty, act as a constructor
 * If the circular linked list is not empty:
   * dynamically allocate the memory for a new node, using data for value
   * point its successor pointer to the first node in the linked list
   * point the successor pointer of the previous node to the new node
   * make the new node the last node
   * update `mSize`

- [ ] `void remove(int data)`
* This function removes a node if its value matches the data

## Test for memory leaks
Test your program for memory leaks

on Linux - use Valgrind tool
````
sudo apt install valgrind
gcc -Wall -g *.c
valgrind --leak-check=full ./a.out
````
on Mac (M1-M2) use leaks tool
````
gcc -Wall -g *.c
leaks --atExit -- ./a.out
````

# Lab 11.2: Eat every nth duck (do at home)
Imagine that we have k ducks swimming in a circle. Ducks are numbered from `1` to `k` in order. There is a crocodile in the middle of the circle. Crocodile eats every nth duck counting from the first. For example, if there are 5 ducks and a crocodile eats every third duck, it will eat the 3rd, 1st, 5th, 2nd, and 4th duck. Your job is to create a function in the CircularLinkedList Class that can perform this action. To do this you will need two more functions:

- [ ] `void remove(Node *dptr)`
* This function removes the next node after the node pointed by dptr. Should it be private or public? 

- [ ] `void eatTheDuck(int n)`
* This function counts nods (ducks) starting with the first one and eats every nth. Eaten duck gets removed from the list

- [ ] Test for memory leaks

Sample Output
````
Ducks in the circle: 1    2    3    4    5
Duck 3 is eaten
The ducks left are: 1    2    4    5
Duck 1 is eaten
The ducks left are: 2    4    5
Duck 5 is eaten
The ducks left are: 2    4
Duck 2 is eaten
The ducks left are: 4
Duck 4 is eaten
The ducks left are: List is empty
````
## Submitting Assignments
It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus.
