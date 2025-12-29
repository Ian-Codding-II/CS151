/**
 * @file library.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "library.h"
#include "customer.h"
#include <cstddef>

/**
 * @brief Method void addBook(string title, string author, unsigned num) adds
 * the book to the library mInventory vector. If a book already exists, it
 * updates the number of books.
 *
 * @param title
 * @param author
 * @param num
 */
void Library::addBook(string title, string author, unsigned num) {
  for (size_t i = 0; i < mInvetory.size(); i++) {
    if (mInvetory[i].myBook.getAuthor() == author &&
        mInvetory[i].myBook.getTitle() == title) {
      mInvetory[i].quantity += num;
      return;
    }
  }
  Books newBook(title, author, num);
  mInvetory.push_back(newBook);
}

/**
 * @brief Method void displayBooks() displays books currently in the library
 * (Including books with quantity = 0)
 *
 */
void Library::displayBooks() const {
  for (size_t i = 0; i < mInvetory.size(); i++) {
    std::cout << "Title: " << mInvetory[i].myBook.getTitle() << endl;
    std::cout << "Author: " << mInvetory[i].myBook.getAuthor() << endl;
    std::cout << "Quantity: " << mInvetory[i].quantity << endl << endl;
  }
}

/**
 * @brief Method int isCustomer(string name) checks if the customer with
 * specified name exist. It returns the position of the customer in the
 * mCustomers vector if the customer exists and -1 otherwise.
 *
 *
 * @param name
 * @return int
 */
int Library::isCustomer(string name) {
  for (size_t i = 0; i < mCustomers.size(); i++) {
    if (mCustomers[i].getName() == name) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief Method void addCustomer(string name) adds a customer to the mCustomer
 * vector with a randomly generated ID number. If the customer already exists,
 * it displays the customer ID number.
 *
 */
void Library::addCustomer(string name) {
  if (isCustomer(name) != -1) {
    std::cout << "Customer with this name already exist. \n";
    std::cout << "Your ID is " << mCustomers[isCustomer(name)].getID() << endl;
  } else {
    int id = rand();
    Customer newCustomer(name, id);
    mCustomers.push_back(newCustomer);
  }
}

/**
 * @brief Method void displayCustomers() displays current customers.
 *
 */
void Library::displayCustomers() {
  std::cout << left;
  for (size_t i = 0; i < mCustomers.size(); i++) {
    std::cout << "Name: " << setw(15)
              << mCustomers[i].getName() // come back if fails to apear nice
              << "ID: " << mCustomers[i].getID() << endl;
  }
}

/**
 * @brief Method void getBook(string name, string title) accepts customer name
 * and book tytle. It checks if the book is available and if the customer
 * exists. If it is it lets's customer borrow the book.
 *
 */
void Library::getBook(string name, string title) {
  for (size_t i = 0; i < mInvetory.size(); i++) {
    if (isCustomer(name) != -1 && mInvetory[i].quantity > 0 &&
        mInvetory[i].myBook.getTitle() == title) {
      mCustomers[isCustomer(name)].borrowBook(mInvetory[i].myBook);
      mInvetory[i].quantity--;
      return;
    }
  }
  std::cout << title << " is not available\n";
}

/**
 * @brief  Method void returnBook(string name, string title) accepts customer
 * name and book tytle. It checks if the book is in the library roster and if
 * the customer has this book. If it is it lets the customer return the book.
 *
 */
void Library::returnBook(string name, string title) {
    if(inLibrary(title) != -1 && mCustomers[isCustomer(name)].hasBook(mInvetory[inLibrary(title)].myBook) != -1){
      mCustomers[isCustomer(name)].returnBook(mInvetory[inLibrary(title)].myBook);
      mInvetory[inLibrary(title)].quantity++;
    }else if (inLibrary(title) == -1){
        std::cout << title << " is from a different library\n";
    }else {
    std::cout << name << " does not have " << title << endl;
    }
}

/**
 * @brief  Method void displayBooks(string name) list the books barrowd by
 * spesific customer
 *
 */
void Library::displayBooks(string name) {
  mCustomers[isCustomer(name)].displayBooks();
}

/**
 * @brief helps find index of a book just like is customer does
 *
 * @param title
 * @return int
 */
int Library::inLibrary(string title) {
  for (size_t i = 0; i < mInvetory.size(); i++) {
    if (mInvetory[i].myBook.getTitle() == title) {
      return i;
    }
  }
  return -1;
}