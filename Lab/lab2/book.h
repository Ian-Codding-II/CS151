/**
 * @file book.h
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
//  Create a Book class.
class Book {
private:
  // with the following attributes: mTitle, and mAuthor.
  std::string mTitle;
  std::string mAuthor;

public:
  //  Implement default constructor and constructor that accepts title and
  //  author (can be combined).
  Book(std::string title = "", std::string auther = "")
      : mTitle(title), mAuthor(auther) {
  } // The order of which these are used in this constructer needs to be in the
    // same order as when I declared them above.

  //  Implement getter and setter functions for member variables.
  //  Remember to add const at the end of getter functions.
  void setAuthor(std::string auther);
  void setTitle(std::string title);
  std::string getAuthor() const;
  std::string getTitle() const;
};

#endif