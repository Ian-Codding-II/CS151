/**
 * @file library.h
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
#include "customer.h"
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Library {
public:
  Library(string name = "") : mName(name) { srand(time(NULL)); };
  void addBook(string title, string author, unsigned num);
  void displayBooks() const; // display books in library
  void addCustomer(string name);
  void displayCustomers(); // display books in library
  void getBook(string name, string title);
  void returnBook(string name, string title);
  void displayBooks(string name); // display books for the customer

private:
  struct Books {
    Book myBook;
    int quantity;
    Books(string title, string author, int num) {
      myBook.setTitle(title);
      myBook.setAuthor(author);
      quantity = num;
    }
  };

  int isCustomer(string name);
  int inLibrary(string title);
  vector<Books> mInvetory;
  vector<Customer> mCustomers;
  string mName;
};

#endif
