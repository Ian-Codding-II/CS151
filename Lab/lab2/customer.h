/**
 * @file customer.h
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "book.h"
#include <iostream>
#include <vector>

using std::string;

//  Create a Customer class with the following attributes: mName, mID, and
//  myBooks as a vector of Book.
class Customer {
private:
  string mName;
  int mID;
  std::vector<Book> myBooks;

public:
  //  Implement default constructor and constructor that accepts name and id
  //  (can be combined).
  Customer(string name = "", int id = 0) : mName(name), mID(id) {}

  //  Implement getter and setter functions for mName and mID member variables.
  //  Remember to add const at the end of getter functions.
  void setName(string name) { mName = name; }
  void setID(int id) { mID = id; }
  string getName() const { return mName; }
  int getID() const { return mID; }

  //  Implement int hasBook(const Book &b) method that checks if the customer
  //  has a specific book. It returns the position of the book in the myBooks
  //  vector if the customer has a book and -1 otherwise. Should it be public or
  //  private?
  int hasBook(const Book &b);

  //  Implement bool borrowBook(const Book &b) method. The customer can only
  //  have one book with the same title and author. If the customer does not
  //  have this book yet, the function adds the book to the myBook vector and
  //  returns true. If the customer already has this book, the function returns
  //  false.
  bool borrowBook(const Book &b);

  //  Implement bool returnBook(const Book &b) method. If the customer has the
  //  book, the function removes the book from the myBook vector and returns
  //  true. If the customer does not have this book, the function returns false.
  bool returnBook(const Book &b);

  //  Implement void displayBooks() method that displays all customer books.
  void displayBooks();
};

#endif