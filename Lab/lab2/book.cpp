/**
 * @file book.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-26
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "book.h"

/**
 * @brief sets the auther
 * 
 * @param auther 
 */
void Book::setAuthor(std::string auther){
    mAuthor = auther;
}

/**
 * @brief sets the title
 * 
 * @param title 
 */
void Book::setTitle(std::string title){
    mTitle = title;
}

/**
 * @brief returns the auther
 * 
 * @return std::string 
 */
std::string Book::getAuthor() const {
    return mAuthor;
}

/**
 * @brief returns the title
 * 
 * @return std::string 
 */
std::string Book::getTitle() const {
    return mTitle;
}