# Lab4: Inheritance

### Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Create and use pointers to create dynamic memory in C++
* Create their own version of vector C++ library
* Understand inheritance


## Quick Review

### Pointers
* A ***pointer variable*** is a variable that ***holds addresses of memory locations***.
* Use ***indirection operator*** `*` to declare a pointer variable
```cpp
int x = 25;
int *intPtr = nullptr;
intPtr = &x;
cout << x << " == " << *intPtr << '\n';  // 25 == 25
*intPtr += 2;
cout << x << " == " << *intPtr << '\n';  // 27 == 27
```

### Dynamic Memory Allocation
* Create variables “on the fly” or allocating memory while the program is already running!
* Use the `new` operator
```cpp
int *intPtr = nullptr;
intPtr = new int;  // dynamically creates memory in the heap
*intPtr = 25;
```
* If you are finished using a dynamically allocated memory, you should free the memory by using the delete operator
```cpp
delete intPtr;
intPtr = nullptr;  // good practice to pair this with delete in most cases
```

### Dynamic Array
```cpp
int *aptr;
aptr = new int[100];  // after this line, treat aptr just like an array
aptr[1] = 24;
aptr[2] = 12;

delete [] aptr;  // free when done using dynamic memory
aptr = nullptr;  // to avoid dangling pointer
```

## Lab 4.1: Implement your own `Vector` class
- [ ] Open Visual Studio Code.
- [ ]  **test.cpp** and  **Vector.h** files are created.  You will be using the three file structure. Thus, you will also need to create  **Vector.cpp**.
- [ ] In **test.cpp**, add a header comment that should look like below,
  ```cpp
  /**
   * @file   test.cpp
   * @author WRITE STUDENT NAME(S)
   * @brief  Implement my own version of the vector that uses
   *         dynamic memory allocation and pointers
   * @date   WRITE DATE TODAY
   *
   */
  ```
- [ ] The vector class is defined in **Vector.h**.
 ### Implementation details for each of the member functions of the `Vector` class
##### `Vector()`
- [ ] Vector will have an initial capacity of 1
- [ ] Assign a dynamic array with a size of 1 to `mElements`
- [ ] What should be the initial values of `mCapacity` and `mSize`?

##### `Vector(int size)`
- [ ] Vector will have mCapacity and mSize = size
- [ ] Assign a dynamic array with a size of mSize to `mElements`
- [ ] Assign value 0 to all elements

##### `~Vector()`
- [ ] Free or release the dynamic array
      
#### `void print()`
- [ ] Display vector, its capacity and size. See the example of the output.
      
##### `void push_back(int data)`
- [ ] If the number of elements (`mSize`) is equal to the capacity, which means we don’t have enough space to accommodate more elements, thus before we can add, you need to increase the capacity of the vector (`mElements`)
  - [ ] Simply double the capacity
  - [ ] Create a temporary pointer variable pointing to a dynamically allocated array with double the current capacity
  - [ ] Copy the existing elements in the vector into the newly created temporary array
  - [ ] Free the memory of the previous or old array
  - [ ] Assign the temporary array as the new vector
- [ ] Add data at the end of the vector
- [ ] Increment mSize

##### `void pop_back()`
* Clue on the implementation of this function:
  - [ ] You only need one very short statement updating one of the member variables
  - [ ] You do not need to resize the dynamic array
  - [ ] Make sure there are elements in the vector

##### `int size() const`
- [ ] Return the current size of the vector

##### `int capacity() const`
- [ ] Return the current capacity of the vector

##### `int& operator[](int index)`
- [ ] Return the reference to the vector element specified by the index
- [ ] Check if the index is valid

### Sample Output
- [ ] The **test.cpp** is created for you
  - [ ] MUST output the same result shown in the sample output below.
  
  ```
  Creating a vector size 5...
  0 0 0 0 0
  Vector size is 5
  Vector capacity is 5

  Creating an empty vector...
  
  Vector size is 0
  Vector capacity is 1
  
  Pushing an element...
  1
  Vector size is 1
  Vector capacity is 1

  Pushing an element...
  1 2
  Vector size is 2
  Vector capacity is 2

  Pushing an element...
  1 2 3
  Vector size is 3
  Vector capacity is 4

  Popping an element...
  1 2
  Vector size is 2
  Vector capacity is 4

  Setting 1st element to 7...
  7 2
  Vector size is 2
  Vector capacity is 4
  ```
- [ ] Commit your code as you deem necessary. (Use **git add -A** and **git commit -m "Tell what you change"**)
- [ ] When to push code.
  - [ ] Push code after every commit. The code in the repo can also serve as a backup copy of your code.
  - [ ] Push your code if you have a question and you would like the instructor to take a look at your code. In this case, you might have to commit your code even though it might have a bug.
  - [ ] Push your code back to GitHub for grading and notify the instructor for grading.
  
## Lab 4.2
- [ ]  Create a derived class called **NewVector** using public Access Specification.
- [ ]  Create a default constructor and destructor that prints to the screen "Child is created..." and "Child is destroyed...".
- [ ]  Add "Parent is created..." and "Parent is destroyed..." count statements to the **Vector** class constructor and destructor.
- [ ]  Comment stuff you have in the main. Create an object of the NewVector class. Call the print function. Observe output.
- [ ]  The **NewVector** class should have access to Vector member variables. What do we need to change in Vector class to make it possible? Hint: member access specifier.
- [ ]  Create one more constructor in the **NewVector** class. It should be the same as **Vector(int size)** constructor. Place court statements in each contractor so that you can distinguish them. Create one more object of the **NewVector** class this time using the size and call a print function. See what contractor is running.
- [ ] Make **NewVector(int size)** constructor use **Vector(int size)** contractor;
- [ ]  Overwrite print function. For example, make it print only the vector elements without size and capacity. Test your code.
- [ ]  Create one more public function in the NewVector class. I used fillWithOnes(). Test it.

## Lab 4.3 (preview for chapter 17)
- [ ]  Create a pointer of **Vector** Class and point it to the object of the **NewVector** Class.
- [ ]  Call the print function using this pointer. Test it. Whose print function is running?
- [ ]  Add virtual to the print function inside the **Vector** class (you may add to both). Re-run the code again. Whose print function is running now?
- [ ]  Try to access the other function you created. Does it work?

## Test for memory leaks
Test your program for memory leaks
* on Linux - use Valgrind tool
````
sudo apt install valgrind
gcc -Wall -g *.c
valgrind --leak-check=full ./a.out
````
* on Mac (M1-M2) use leaks tool
````
gcc -Wall -g *.c
leaks --atExit -- ./a.out
````
> Note: no space between `--` and `atExit`, space between `--` and name of the executable.

## Submitting Lab Assignments
- [ ] Ensure that you push your local copy of this lab's repo to GitHub. Verify that the code in GitHub is the same code you have on your local computer.
- [ ] You may continue to update and push your code into this repo as long as it is before the deadline.
- [ ] It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this programming assignment in Canvas. This allows the instructor to be notified of your final submission and that you are ready for grading.
