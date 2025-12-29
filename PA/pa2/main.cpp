/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief give info from file based on what menu option the user decides.
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "index.h"

int main() {
    // Step 1: Show the menu to the user,
    // and prompt the user to select from the menu.
    // Ensure that the program validates user input.
    // Prompt the user when an invalid menu option is selected.
    int choice = 0;
    StudentManager manager;
    if (!manager.loadFromCSV("grades.csv")) {
        cout << "Failed to load data!\n";
        return 1;
    }
    manager.loadFirstLastSSN();
    for (int i = 0; i < 3; i++) {
        manager.insertionSort(i);
    }

    do {
        choice = menu(choice);

        // Step 2: If the user selects a valid menu,
        // print out the output. For printing data,
        // format the output using formatting options under for proper alignment.
        switch (choice) {
        case 1:
            system("clear");
            cout << "Sorted by last name\n";
            manager.displayData(0);
            break;
        case 2:
            system("clear");
            cout << "Sorted by first name\n";
            manager.displayData(1);

            break;
        case 3:
            system("clear");
            cout << "Sorted by SSN\n";
            manager.displayData(2);

            break;
        case 4: {
            system("clear");
            string lastName;
            cout << "Enter Last Name: ";
            getline(cin, lastName);
            cout << std::endl;
            manager.searchTypes(lastName, 0);
            break;
        }
        case 5:{
            system("clear");
            string firstName;
            cout << "Enter First Name: ";
            getline(cin, firstName);
            cout << std::endl;
            manager.searchTypes(firstName, 1);
            break;
        }
        case 6:{
            system("clear");
            string SSN;
            cout << "Enter SSN: ";
            getline(cin, SSN);
            cout << std::endl;
            manager.searchTypes(SSN, 2);
            break;
        }
        default: // Step 3: The program only exits when the user selects the correct menu to exit.
            system("clear");
            break;
        }

    } while (choice != maxChoice);
    return 0;
}