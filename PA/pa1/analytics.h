/**
 * @file analytics.h
 * @author Ian Codding II
 * @brief All declarations for this project.
 * @version 0.1
 * @date 2025-08-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::string;

struct GradEmploymentData {
  GradEmploymentData();
  int demographicsTotal; // The estimated total of people awarded degrees in
                         // this major during 2005
  string educationMajor; // The name of the major for these graduated students
  float meanSalary; // The average (mean) recorded salary reported for employed
                    // people with this degree
  float medianSalary; // The median recorded salary reported for employed people
                      // with this degree
  int demographicsAsian; // The estimated number of people identifying as Asian
                         // that were awarded degrees in this major
  int demographicsMinority; // The estimated number of people identifying as
                            // minority (e.g., Black, African American, Native
                            // American) that were awarded degrees in this major
  int demographicsWhite; // The estimated number of people identifying as White
                         // that were awarded degrees in this major
  int demographicsFemales; // The estimate number of women awarded degrees in
                           // this major
  int demographicsMales;   // The estimate number of men awarded degrees in this
                           // major
  int educationBachelor;  // The estimated number of bachelor degrees awarded in
                          // this for major
  int educationDoctorate; // The estimated number of doctoral degrees awarded in
                          // this for major
  int educationMasters;   // The estimated number of Masters awarded in this for
                          // major
};

class GraduateDataManager {
private:
  // Private data member
  std::vector<GradEmploymentData> data;

  // Private helper functions
  void insertionSortByMajor(); // check
  bool binarySearchMajor(const string &major,
                         size_t &index) const; // check
  void bubbleSort(int field, bool ascending);  // check
  string toLowerCase(const string &str) const; // check

public:
  // Public interface
  GraduateDataManager() = default;
  bool loadFromCSV(const string &filename);     // check
  void sortByField(int option, bool ascending); // For menu options 1-8: check
  void searchMajor(const string &major);        // For menu option 11
  void displayCustomInfo(int option, string major); // For menu options 9-10
  void displayData(int index = -1) const;           // view all data: temp test
};

void menu(int &choice);
bool checkNum(int &num);
void enter();

const int maxChoice = 12;
const int minChoice = 1;

#endif
