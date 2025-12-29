/**
 * @file index.cpp
 * @author Ian Codding II
 * @brief This is where I have defined all my functions.
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "index.h"
#include "myCode.h"

/**
 * @brief Displays the menu and returns the users choice.
 *
 * @param choice
 */
int menu(int choice) {
    bool check = false;
    do {
        system("clear");
        cout << "1. Print data in ascending order by last name\n"
             << "2. Print data in ascending order by first name\n"
             << "3. Print data in ascending order by SSN\n"
             << "4. Search by last name\n"
             << "5. Search by first name\n"
             << "6. Search by SSN\n"
             << "7. Exit\n"
             << std::endl
             << "Select a Menu: ";
        check = checkNum(choice);
        if (check) {
            cout << "There was an error processing your input!\n"
                 << "Please make sure you are not entering any spaces or charecters "
                    "with your input.\n";
            enter();
        }
    } while (check);
    return choice;
}

/**
 * @brief searches an array or vector for the desired type
 *
 * @param major major to search for
 * @param index where it is
 * @return true
 * @return false
 */
bool StudentManager::binarySearch(const string &type, std::vector<size_t> &index, int option) {
    std::vector<Student *> *ptr;
    if (option == 0) {
        ptr = &lastNamePtr;
    } else if (option == 1) {
        ptr = &firstName;
    } else {
        ptr = &SSNPtr;
    }

    if (ptr->size() == 0) {
        return false;
    }
    int first = 0,                                // First array element
        last = static_cast<int>(ptr->size()) - 1; // Last array element
    int middle;                                   // Midpoint of search
    bool found = false;                           // Flag
    while (first <= last) {
        middle = (first + last) / 2; // Calculate midpoint

        string dataIndex = (option == 0 ? toLowerCase((*ptr)[middle]->lastName)
                                        : (option == 1 ? toLowerCase((*ptr)[middle]->firstName)
                                                       : toLowerCase((*ptr)[middle]->ssn)));
        string dataFind = toLowerCase(type);

        if (dataIndex == dataFind) // If value is found at mid
        {

            found = true;
            index.push_back(middle);

            // Search left of middle
            int left = middle - 1;
            while (left >= 0) {
                std::string leftVal = toLowerCase(
                    option == 0 ? (*ptr)[left]->lastName : (option == 1 ? (*ptr)[left]->firstName : (*ptr)[left]->ssn));
                if (leftVal == dataFind)
                    index.push_back(left--);
                else
                    break;
            }

            // Search right of middle
            int right = middle + 1;
            while (right < static_cast<int>(ptr->size())) {
                std::string rightVal = toLowerCase(
                    option == 0 ? (*ptr)[right]->lastName : (option == 1 ? (*ptr)[right]->firstName : (*ptr)[right]->ssn));
                if (rightVal == dataFind)
                    index.push_back(right++);
                else
                    break;
            }

            break;                       // Found all matches; exit binary search
        } else if (dataIndex > dataFind) // If value is in lower half
        {
            last = middle - 1;
        } else {
            first = middle + 1; // If value is in upper half
        }
    }
    return found;
}

/**
 * @brief sorts the array or vector vea pointers.
 *
 */
void StudentManager::insertionSort(int option) {
    std::vector<Student *> *ptr;
    if (option == 0) {
        ptr = &lastNamePtr;
    } else if (option == 1) {
        ptr = &firstName;
    } else {
        ptr = &SSNPtr;
    }
    for (size_t startScan = 1; startScan < (*ptr).size(); ++startScan) {
        Student *key = (*ptr)[startScan];
        int index = static_cast<int>(startScan) - 1;
        while (index >= 0 && ((option == 0) ? (toLowerCase((*(*ptr)[index]).lastName) >
                                               toLowerCase((*key).lastName))
                                            : (option == 1 ? (toLowerCase(((*(*ptr)[index]).firstName)) >
                                                              toLowerCase((*key).firstName))
                                                           : (*(*ptr)[index]).ssn > (*key).ssn))) {
            (*ptr)[index + 1] = (*ptr)[index];
            --index;
        }
        (*ptr)[index + 1] = key;
    }
}

/**
 * @brief loads the data from the csv to the objects.
 *
 * @param filename
 * @return true
 * @return false
 */
bool StudentManager::loadFromCSV(const string &filename) {
    string line;
    Student info;
    char delim = ',';
    std::ifstream file(filename);
    if (file.fail()) {
        return false;
    }

    std::getline(file, line, '\n');

    while (file.peek() != EOF) {
        std::getline(file, line, delim);
        info.id = std::stoi(line); // string to int

        std::getline(file, info.lastName, delim);

        std::getline(file, info.firstName, delim);

        std::getline(file, info.ssn, delim);

        size_t length = (sizeof(info.test) / sizeof(info.test[0]));
        for (size_t i = 0; i < length; i++) {
            std::getline(file, line, delim);
            info.test[i] = std::stof(line); // string to float
        }

        std::getline(file, line, delim);
        info.final = std::stof(line); // string to int

        std::getline(file, info.letterGrade, '\n');

        data.push_back(info);
    }

    return true;
}

/**
 * @brief View all data
 *
 */
void StudentManager::displayData(int option) {
    // for (int i = 0; i < 3; i++) {
    //     insertionSort(i);
    // }

    std::vector<Student *> *ptr;
    if (option == 0) {
        ptr = &lastNamePtr;
    } else if (option == 1) {
        ptr = &firstName;
    } else {
        ptr = &SSNPtr;
    }

    cout << std::right << std::setw(2) << "ID" << std::setw(11)
         << "Last Name" << std::setw(12)
         << "First Name" << std::setw(4)
         << "SSN" << std::setw(15) << "Grade\n" << std::setw(0);
    for (size_t i = 0; i < ptr->size(); i++) {
        Student *s = (*ptr)[i];

        cout << std::right
             << std::setw(2) << s->id
             << std::left
             << "  "
             << std::setw(11) << s->lastName
             << std::setw(11) << s->firstName
             << std::setw(12) << s->ssn;

        cout << s->letterGrade
             << std::endl;
    }
    enter();
}

/**
 * @brief Loads the three vectors of string pointers.
 *
 */
void StudentManager::loadFirstLastSSN() {
    for (size_t i = 0; i < data.size(); i++) {
        firstName.push_back(&data[i]);
        lastNamePtr.push_back(&data[i]);
        SSNPtr.push_back(&data[i]);
    }
}

/**
 * @brief searches for a specific thing depending on option
 * 
 * @param type 
 * @param option 
 */
void StudentManager::searchTypes(const string &type, int option) {
    // for (int i = 0; i < 3; i++) {
    //     insertionSort(i);
    // }

    std::vector<Student *> *ptr;
    if (option == 0) {
        ptr = &lastNamePtr;
    } else if (option == 1) {
        ptr = &firstName;
    } else {
        ptr = &SSNPtr;
    }

    std::vector<size_t> index;
    if (binarySearch(type, index, option)) {
        for (size_t i = 0; i < index.size(); i++) {
            cout << (*ptr)[index[i]]->id << ", " << (*ptr)[index[i]]->lastName
                 << ", " << (*ptr)[index[i]]->firstName << ", " << (*ptr)[index[i]]->ssn << ", ";
            for (size_t j = 0; j < (sizeof((*ptr)[index[i]]->test) / sizeof((*ptr)[index[i]]->test[0])); j++) {
                cout << (*ptr)[index[i]]->test[j] << ", ";
            }
            cout << (*ptr)[index[i]]->final << ", "
                 << (*ptr)[index[i]]->letterGrade << std::endl;
        }
    } else {
        cout << "Not found.\n";
    }
    enter();
}