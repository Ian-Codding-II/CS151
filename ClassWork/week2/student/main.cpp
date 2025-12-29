/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-08-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "student.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  Student s1;
  std::string input;
  cout << "Enter a name: ";
  getline(cin, input);
  if (s1.setName(input)) {
    cout << "Student name is " << s1.getName() << endl;
  }else {
    cout << "Name can't be set\n";
  }

  Student s2("Tom Cook", 0327768, 4.0);

  return 0;
}