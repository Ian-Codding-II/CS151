/**
 * @file customer.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "customer.h"

/**
 * @brief checks if the customer has a specific book.
 *
 * @param b
 * @return int returns the position of the book in the myBooks vector if the
 * customer has a book and -1 otherwise.
 */
int Customer::hasBook(const Book &b) {
  for (size_t i = 0; i < myBooks.size(); i++) {
    if (myBooks[i].getAuthor() == b.getAuthor() &&
        myBooks[i].getTitle() == b.getTitle()) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief The customer can only have one book with the same title and author. If
 * the customer does not have this book yet, the function adds the book to the
 * myBook vector and returns true. If the customer already has this book, the
 * function returns false.
 *
 * @param b
 * @return true
 * @return false
 */
bool Customer::borrowBook(const Book &b) {
  int index = hasBook(b);
  if (index != -1) {
    return false;
  } else {
    myBooks.push_back(b);
    return true;
  }
}

/**
 * @brief If the customer has the book, the function removes the book from the
 * myBook vector and returns true. If the customer does not have this book, the
 * function returns false.
 *
 * @param b
 * @return true
 * @return false
 */
bool Customer::returnBook(const Book &b) {
  int index = hasBook(b);
  if (index == -1) {
    return false;
  } else {
    myBooks.erase(myBooks.begin() + index);
    return true;
  }
}

/**
 * @brief Implement void displayBooks() method that displays all customer books.
 *
 */
void Customer::displayBooks() {
    for(size_t i = 0; i < myBooks.size(); i++){
        std::cout << "Title: " << myBooks[i].getTitle() << std::endl;
        std::cout << "   Author: " << myBooks[i].getAuthor() << std::endl;
    }
}
