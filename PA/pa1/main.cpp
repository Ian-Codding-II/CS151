/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief This is a data analytics program. Users can interact with this program
 * by selecting a menu and following the instructions of the program.
 * @version 0.1
 * @date 2025-08-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "analytics.h"
#include <cstddef>
#include <cstdlib>

int main() {
  GraduateDataManager manager;
  int num = 0;
  srand(time(NULL));

  if (!manager.loadFromCSV("graduates2015.csv")) {
    cout << "Failed to load data!\n";
    return 1;
  }

  do {
    menu(num);

    switch (num) {
    case 1:
      system("clear");
      manager.sortByField(num, false);
      break;
    case 2:
      system("clear");
      manager.sortByField(num, true);
      break;
    case 3:
      system("clear");
      manager.sortByField(num, false);
      break;
    case 4:
      system("clear");
      manager.sortByField(num, true);
      break;
    case 5:
      system("clear");
      manager.sortByField(num, false);
      break;
    case 6:
      system("clear");
      manager.sortByField(num, true);
      break;
    case 7:
      system("clear");
      manager.sortByField(num, false);
      break;
    case 8:
      system("clear");
      manager.sortByField(num, true);
      break;
    case 9: {
      system("clear");
      manager.displayCustomInfo(num, "nano");
      break;
    }
    case 10: {
      system("clear");
      string major;
      cout << "Enter major: ";
      getline(cin, major);
      cout << endl;
      manager.displayCustomInfo(num, major);
      break;
    }
    case 11: {
      system("clear");
      string major;
      cout << "Enter major: ";
      getline(cin, major);
      cout << endl;
      manager.searchMajor(major);
      break;
    }
    case 12:
      system("clear");
      break;
    }
  } while (num != maxChoice);

  return 0;
}