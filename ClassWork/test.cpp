/**
 * @file test.cpp
 * @author Ian Codding II
 * @brief Test
 * @version 0.1
 * @date 2025-08-18
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
using namespace std;
int main() {
  int x=0;
  int y=1;
  for (int i = 0; i < (y+1); i++) {
    x=x+(y-i+1);
    cout << x << endl;
  }
  cout << endl;
  return 0;
}