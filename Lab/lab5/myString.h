/**
 * @file myString.h
 * @author Ian Codding II
 * @brief 
 * @version 0.1
 * @date 2025-09-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <cstddef>

using std::cout, std::cin, std::endl;

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
    int find(const String &s) const;

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

#endif