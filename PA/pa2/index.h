/**
 * @file index.h
 * @author Ian Codding II
 * @brief All declarations for this project.
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef INDEX_H
#define INDEX_H
#include "myCode.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using std::string, std::cout, std::cin;

struct Student {
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};

class StudentManager {
  private:
    // Private data member
    std::vector<Student> data;
    std::vector<Student *> lastNamePtr;
    std::vector<Student *> firstName;
    std::vector<Student *> SSNPtr;
    // Private helper functions
    bool binarySearch(const string &type, std::vector<size_t> &index, int option); // check

  public:
    // Public interface
    void insertionSort(int option); // Moved to sort globaly.
    StudentManager() = default;
    void loadFirstLastSSN();                           // check
    bool loadFromCSV(const string &filename);          // check
    void searchTypes(const string &types, int option); // check
    void displayData(int option);                      // View all data
};

int menu(int choice);

#endif