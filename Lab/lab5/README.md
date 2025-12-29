# Lab5: String Class

### Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Create and use pointers to create dynamic memory in C++
* Create their own version of string class C++ library

### Acknowledgments
Content used in this assignment is based upon information in the following sources:
* None

## Implement your own String class
- [ ] Open Visual Studio Code.
- [ ] Create two files: **myString.h**, and **myString.cpp**
- [ ] Use the code below to represent your version of the `string` class.
  ```cpp
  class String
  {
  public:
      String();
      String(const char *s);
      String(const String &str); // copy constructor
      ~String();                 // destructor

      //copy s into String object
      String& copy(const char *s);
      String& copy(const String &s);

      String& operator=(const char *s);
      String& operator=(const String &s);

      // Searches the string for the first occurrence of the sequence 
      // specified by its arguments. Returns the starting index where
      // the string is found. If not found, return -1.
      int find(const char *s) const;

      // The substring is the portion of the object that starts at 
      // character position pos and spans len characters 
      // (or until the end of the String, whichever comes first).
      // len = -1 indicates all characters until the end of the String
      String substr(int pos=0, int len=-1) const;

      // Returns a pointer to an array that contains a null-terminated 
      // sequence of characters (i.e., a C-string) representing the 
      // current value of the string object.
      const char* c_str() const;

      // Get character in String
      char& at(int index);
      char& operator[](int index);

      // Return the length of String
      int length() const;
      int size() const;

  private:
      char *mString;
      int mSize;
  };
  ```
- [ ] Follow the step-by-step instructions embedded in **test.cpp**. Go through each step in order to complete this lab.
- [ ] Commit your code frequently.

### Implementation details for each of the member functions of the `class String`
##### `String()`
- [ ] Add this as the first statement of this function
  ```cpp
  cout << "Default constructor got called!\n";
  ```
- [ ] Assign a dynamic array with a size of 1 to `mString`
- [ ] Initialize the first element of `mString` to the null character
- [ ] What should be the initial value of `mSize`?

##### `String(const char *s)`
- [ ] Add this as the first statement of this function
  ```cpp
  cout << "String(const char*s) got called!\n";
  ```
- [ ] Set `mSize` to the length of the C-string s
- [ ] Assign a dynamic array with a size of `mSize + 1` to `mString`
- [ ] Use the C-string function to copy the C-string s into `mString`

##### `String(const String &str)`
- [ ] Add this as the first statement of this function
  ```cpp
  cout << "String(const String& str) got called!\n";
  ```
- [ ] Set `mSize` to the length of `str`
- [ ] Assign a dynamic array with a size of `mSize + 1` to `mString`
- [ ] Use the C-string function to copy the C-string member variable of `str` into `mString`

##### `~String()`
- [ ] Add this as the first statement of this function
  ```cpp
  cout << "Destructor got called!\n";
  ```
- [ ] Free the dynamic memory of `mString`

##### `const char* c_str() const`
- [ ] This is the getter function for `mString`

##### `int length() const`
##### `int size() const`
- [ ] Both member functions are the getter function for `mSize`

##### `String& copy(const char *s)`
- [ ] Copy s into a String object
- [ ] If `mString` does not have enough memory to copy the contents of `s`, then 
  - [ ] Free the dynamic memory of `mString` 
  - [ ] Create enough memory
- [ ] In all cases,
  - [ ] Set `mSize` to the length of the C-string `s`
  - [ ] Using the C-string function to copy the C-string `s` into `mString`
  - [ ] The `return` statement should be
    ```cpp
    return *this;  
    ```
    
##### `String& operator=(const char *s)`
- [ ] Same code as `copy(const char *s)`. Should you rewrite or can you just call a function?

##### `String& copy(const String &s)`
- [ ] Copy s into String object
- [ ] If `mString` does not have enough memory to copy the contents of `s`, then 
  - [ ] Free the dynamic memory of `mString` 
  - [ ] Create enough memory
- [ ] In all cases,
  - [ ] Set `mSize` to the length of `str`
  - [ ] Use the C-string function to copy the C-string member variable of `str` into `mString`
  - [ ] The `return` statement should be
    ```cpp
    return *this;  
    ```

##### `String& operator=(const String &s)`
- [ ] Same code as `copy(const String &s)`. Should you rewrite or can you just call a function?

##### `char& at(int index)`
- [ ] Return the element in the array of characters based on the index

##### `char& operator[](int index)`
- [ ] Same as `at(int index)`

##### `int find(const char *s) const`
- [ ] Searches the string for the first occurrence of the sequence specified by its arguments. 
- [ ] Returns the starting index where the string is found. If not found, return `-1`.
- [ ] `s` is the C-string to search for

##### `String substr(int pos, int len) const`
> The substring is the portion of the object that starts at character position `pos` and spans `len` characters (or until the end of the `String`, whichever comes first). `len = -1` indicates all characters until the end of the `String`
- [ ] Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
- [ ] The substring is the portion of the object that starts at character position `pos` and spans `len` characters (or until the end of the string, whichever comes first).

### Code Output
Once you go through all the instructions in test.cpp, you will have the following output:
```
Hi
Hello
Hello
Hello
I am starting to get smarter
I am really getting smarter!
I am really getting smarter!
I am still craving for more knowledge!
a m
A M
I Am Still Craving For More Knowledge!
7
24
28
13
-1
24
My code is getting smarter!
My String class is so smart
```
### Test for memory leaks
Test your program for memory leaks
* on Linux - use Valgrind tool
````
sudo apt install valgrind
g++ -Wall -g *.cpp
valgrind --leak-check=full ./a.out
````
* on Mac (M1-M2) use leaks tool
````
g++ -Wall -g *.cpp
leaks --atExit -- ./a.out
````
> Note: no space between `--` and `atExit`, space between `--` and the name of the executable.


- [ ] **Present your work to the instructor**. Prepare to answer questions. Once the code is inspected and graded, make sure the code is committed and pushed to the repo. 

## Submitting Lab Assignments
- [ ] It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.
