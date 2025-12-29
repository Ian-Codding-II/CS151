/**
 * @file myString.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "myString.h"
/**
 * @brief Construct a new String object
 *
 */
String::String() {
    // std::cout << "Default constructor got called!\n";
    mString = new char[1];
    mString[0] = '\0';
    mSize = 0;
}

/**
 * @brief Construct a new String object
 *
 * @param s
 */
String::String(const char *s) {
    // std::cout << "String(const char*s) got called!\n";
    // Set mSize to the length of the C-string s
    mSize = strlen(s);
    // Assign a dynamic array with a size of mSize + 1 to mString
    mString = new char[mSize + 1];
    // Use the C-string function to copy the C-string s into mString
    strcpy(mString, s);
}

/**
 * @brief Construct a new String object
 *
 * @param str
 */
String::String(const String &str) {
    // std::cout << "String(const String& str) got called!\n";
    // Set mSize to the length of str
    mSize = str.length();
    // Assign a dynamic array with a size of mSize + 1 to mString
    mString = new char[mSize + 1];
    // Use the C-string function to copy the C-string member variable of str into mString
    strcpy(mString, str.c_str());
} // copy constructor

/**
 * @brief Destroy the String object
 *
 */
String::~String() {
    // std::cout << "Destructor got called!\n";
    delete[] mString;
} // destructor

/**
 * @brief copy s into String object
 *
 * @param s
 * @return String&
 */
String &String::copy(const char *s) {
    if (static_cast<long unsigned>(mSize) < strlen(s)) {
        delete[] mString;
        mString = new char[strlen(s) + 1];
    }
    mSize = strlen(s);
    strcpy(mString, s);
    return *this;
}

/**
 * @brief copy string into String object
 *
 * @param s
 * @return String&
 */
String &String::copy(const String &s) {
    if (mSize < s.size()) {
        delete[] mString;
        mString = new char[s.size() + 1];
    }
    mSize = s.size();
    strcpy(mString, s.c_str());
    return *this;
}

/**
 * @brief copy data data from one s to another string
 *
 * @param s
 * @return String&
 */
String &String::operator=(const char *s) {
    return this->copy(s);
}

/**
 * @brief copy data data from one string to another string
 *
 * @param s
 * @return String&
 */
String &String::operator=(const String &s) {
    return this->copy(s);
}

/**
 * @brief Searches the string for the first occurrence of the sequence
 * specified by its arguments. Returns the starting index where
 * the string is found. If not found, return -1.
 *
 * @param s
 * @return int
 */
int String::find(const char *s) const {
    bool match = true;
    for (size_t i = 0; i < (length() - strlen(s)); i++) {
        match = false;
        if (mString[i] == s[0]) {
            match = true;
            for (int j = i + 1, k = 1; static_cast<size_t>(j) < strlen(s) + i; j++, k++) {
                if (s[k] != mString[j]) {
                    match = false;
                    break;
                }
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Searches the string for the first occurrence of the sequence
 * specified by its arguments. Returns the starting index where
 * the string is found. If not found, return -1.
 * 
 * @param s 
 * @return int 
 */
int String::find(const String &s) const {
    bool match = true;
    for (size_t i = 0; static_cast<int>(i) < (length() - s.length()); i++) {
        match = false;
        if (mString[i] == s.mString[0]) {
            match = true;
            for (int j = i + 1, k = 1; static_cast<size_t>(j) < s.length() + i; j++, k++) {
                if (s.mString[k] != mString[j]) {
                    match = false;
                    break;
                }
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}


/**
 * @brief The substring is the portion of the object that starts at
 * character position pos and spans len characters
 * (or until the end of the String, whichever comes first).
 * len = -1 indicates all characters until the end of the String
 *
 * @param pos
 * @param len
 * @return String
 */
String String::substr(int pos, int len) const {
    String temp;
    temp.mSize = size();
    int i = 0;
    for (int j = pos; j < (len == -1 ? length() : len + pos) && j < length(); j++) {
        temp[i] = mString[j];
        i++;
    }
    return temp;
}

/**
 * @brief Returns a pointer to an array that contains a null-terminated
 * sequence of characters (i.e., a C-string) representing the
 * current value of the string object.
 *
 * @return const char*
 */
const char *String::c_str() const {
    return mString;
}

/**
 * @brief Get character in String
 *
 * @param index
 * @return char&
 */
char &String::at(int index) {
    return (mString[index]);
}

/**
 * @brief retreae a speific index
 *
 * @param index
 * @return char&
 */
char &String::operator[](int index) {
    return (at(index));
}

/**
 * @brief Return the length of String
 *
 * @return int
 */
int String::length() const {
    return strlen(mString);
}

/**
 * @brief Return size of string
 *
 * @return int
 */
int String::size() const {
    return mSize;
}