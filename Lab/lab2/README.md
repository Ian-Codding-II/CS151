# Lab 2: Library class

### Learner Objectives
At the conclusion of this lab assignment, participants should be able to:
* Define, implement, and use a classes
* Practice object composition 

## Part I - Book class
  - [ ] Create a `Book` class with the following attributes: `mTitle`, and `mAuthor`. 
  - [ ] Implement default constructor and constructor that accepts `title` and `author` (can be combined).
  - [ ] Implement getter and setter functions for member variables.
  - [ ] Remember to add `const` at the end of getter functions.

## Part II - Customer class
  - [ ] Create a `Customer` class with the following attributes: `mName`, `mID`, and `myBooks` as a vector of `Book`. 
  - [ ] Implement default constructor and constructor that accepts `name` and `id` (can be combined).
  - [ ] Implement getter and setter functions for `mName` and `mID` member variables.
  - [ ] Remember to add `const` at the end of getter functions.
  - [ ] Implement `int hasBook(const Book &b)` method that checks if the customer has a specific book. It returns the position of the book in the `myBooks` vector if the customer has a book and -1 otherwise. Should it be public or private?
  - [ ] Implement `bool borrowBook(const Book &b)` method. The customer can only have one book with the same title and author. If the customer does not have this book yet, the function adds the book to the `myBook` vector and returns true.  If the customer already has this book, the function returns false.
  - [ ] Implement `bool returnBook(const Book &b)` method. If the customer has the book, the function removes the book from the `myBook` vector and returns true.  If the customer does not have this book, the function returns false.
  - [ ] Implement `void displayBooks()` method that displays all customer books.

## Part III - Library class
  - [ ] The definition of `library.h` is provided for you.
  - [ ] Implement each member function in the `library.cpp` file.
  - [ ] Constructor `Library(string name="")`: sets `mName` and creates a seed for the random number generator.
  - [ ] Method `void addBook(string title, string author, unsigned num)` adds the book to the library `mInventory` vector. If a book already exists, it updates the number of books.
  - [ ] Method `void displayBooks()` displays books currently in the library (Including books with quantity = 0)
  - [ ] Method `int isCustomer(string name)` checks if the customer with specified name exist. It returns the position of the customer in the `mCustomers` vector if the customer exists and -1 otherwise.
  - [ ] Method `void addCustomer(string name)` adds a customer to the mCustomer vector with a randomly generated ID number. If the customer already exists, it displays the customer ID number.
  - [ ] Method `void displayCustomers()` displays current customers.
  - [ ] Method `void getBook(string name, string title)` accepts customer name and book tytle. It checks if the book is available and if the customer exists. If it is it lets's customer borrow the book.
  - [ ] Method `void returnBook(string name, string title)` accepts customer name and book tytle. It checks if the book is in the library roster and if the customer has this book. If it is it lets the customer return the book.
  - [ ] Method `void displayBooks(string name)` list the books barrowd by spesific customer.

## Part IV - main.cpp
- [ ] `main` function is provided for you.
- [ ] Run the program and compare the output with the output below
- [ ] For your convenience `check.sh` script is provided. To run the script,
* Make it executable: `chmod +x check.sh`
* Run it: `./check.sh`  
````
***********Books currently at the library:***************
Title: The Adventures of Tom Sawyer
Author: Mark Twain
Quantity: 4

Title: A Game of Thrones: A Song of Ice and Fire
Author: George R.R. Martin
Quantity: 1

Title: The Call of the Wild
Author: Jack London
Quantity: 4

Adding Tom as a customer...
Adding Tom as a customer again...
Customers with this name already exist.
Your ID is 953655969

###############Tom is getting books...##################
A Game of Thrones: A Song of Ice and Fire...
A Game of Thrones: A Song of Ice and Fire...again...
A Game of Thrones: A Song of Ice and Fire is not available
The Adventures of Tom Sawyer...
White Fang...
White Fang is not available

################List of Tom's books:####################
Title: A Game of Thrones: A Song of Ice and Fire
   Author: George R.R. Martin
Title: The Adventures of Tom Sawyer
   Author: Mark Twain

***********Books currently at the library:***************
Title: The Adventures of Tom Sawyer
Author: Mark Twain
Quantity: 3

Title: A Game of Thrones: A Song of Ice and Fire
Author: George R.R. Martin
Quantity: 0

Title: The Call of the Wild
Author: Jack London
Quantity: 4

Adding Sam as a customer...

###############Sam is getting books...##################
A Game of Thrones: A Song of Ice and Fire...
A Game of Thrones: A Song of Ice and Fire is not available
The Adventures of Tom Sawyer...

################List of Sams's books:####################
Title: The Adventures of Tom Sawyer
   Author: Mark Twain

***********Books currently at the library:***************
Title: The Adventures of Tom Sawyer
Author: Mark Twain
Quantity: 2

Title: A Game of Thrones: A Song of Ice and Fire
Author: George R.R. Martin
Quantity: 0

Title: The Call of the Wild
Author: Jack London
Quantity: 4


###############Tom is returning books...##################
A Game of Thrones: A Song of Ice and Fire...
A Game of Thrones: A Song of Ice and Fire...again...
Tom Cook does not have A Game of Thrones: A Song of Ice and Fire
White Fang...
White Fang is from a different library

################List of Tom's books:####################
Title: The Adventures of Tom Sawyer
   Author: Mark Twain

***********Books currently at the library:***************
Title: The Adventures of Tom Sawyer
Author: Mark Twain
Quantity: 2

Title: A Game of Thrones: A Song of Ice and Fire
Author: George R.R. Martin
Quantity: 1

Title: The Call of the Wild
Author: Jack London
Quantity: 4


**********Customers currently at the library:*************
Name: Tom Cook       ID: 953655969
Name: Sam Miller     ID: 1425841671
````
## Part IV (extra)
 - [ ] Implement file I/O to save and load library data (books and customers) between program runs.
 - [ ] Library constructor should load data from the `data` file
 - [ ] Library destructor should store data in the `data` file.
 

## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
