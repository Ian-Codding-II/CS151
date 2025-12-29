/**
 * @file analytics.cpp
 * @author Ian Codding II
 * @brief This is where I have defined all my functions.
 * @version 0.1
 * @date 2025-08-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "analytics.h"

/**
 * @brief Displays the menu and returns the users choice.
 *
 * @param choice
 */
void menu(int &choice) {
    bool check = false;
    do {
        system("clear");
        cout
            << "2015 National Survey of Recent College Graduate\n"
            << "1. Top 10 Majors with the Highest Mean Salary\n"
            << "2. Top 10 Majors with the Lowest Mean Salary\n"
            << "3. Top 10 Majors with the Highest Median Salary\n"
            << "4. Top 10 Majors with the Lowest Median Salary\n"
            << "5. What are the Top 5 Majors with the Highest Number of Asians\n"
            << "6. What are the Top 5 Majors with the Lowest Number of Asians\n"
            << "7. What are the Top 5 Majors with the Highest Number of "
               "Minorities\n"
            << "8. What are the Top 5 Majors with the Lowest Number of Minorities\n"
            << "9. Dont know where to begin? Let me help you get started with a "
               "random draw of an education.\n"
            << "10. See a specific majors percentage of each demographic.\n"
            << "11. Display Information for a Specific Major\n"
            << "12. Exit\n"
            << endl
            << "Select a Menu: ";

        check = checkNum(choice);
        if (check) {
            cout << "There was an error processing your input!\n"
                 << "Please make sure you are not entering any spaces or charecters "
                    "with your input.\n";
            enter();
        }
    } while (check);
}

/**
 * @brief Validates the users number to the perameters instructed upon.
 *
 * @param num
 * @return true
 * @return false
 */
bool checkNum(int &num) {
    num = 0;

    string input;
    bool flaged = false;
    int n = '0';

    std::getline(cin, input);
    for (size_t i = 0; i < input.size(); i++) {
        if (!std::isdigit(input[i])) {
            flaged = true; // if found then no good
        } else {
            if (i > 0) {
                num * 10;
            }
            num = input[i] + num - n;
        }
    }

    if (flaged || num > maxChoice || num < minChoice) {
        return true; // this tells me to go again
    }

    return false;
}

/**
 * @brief I feel this takes care of most errors that can happen before someone
 * presses enter. Which is why I dont just do cin.get.
 *
 */
void enter() {
    string input = "";
    cout << "\nPress enter to continue...";
    std::getline(cin, input);

    return;
}

/**
 * @brief searches an array or vector for the desired educationMajor
 *
 * @param major major to search for
 * @param index where it is
 * @return true
 * @return false
 */
bool GraduateDataManager::binarySearchMajor(const string &major,
                                            size_t &index) const {
    index = data.size(); // Position of search value set out of bounds

    if (data.size() == 0)
        return false;
    int first = 0,              // First array element
        last = data.size() - 1, // Last array element
        middle;                 // Midpoint of search
    bool found = false;         // Flag
    while (!found && first <= last) {
        middle = (first + last) / 2; // Calculate midpoint
        string dataIndex = toLowerCase(data[middle].educationMajor);
        string dataFind = toLowerCase(major);
        if (dataIndex == dataFind) // If value is found at mid
        {
            found = true;
            index = middle;
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
 * @brief sorts the array or vector.
 *
 */
void GraduateDataManager::insertionSortByMajor() {
    for (size_t startScan = 1; startScan < data.size(); ++startScan) {
        GradEmploymentData key = data[startScan];
        int index = startScan - 1;
        // string dataIndex = toLowerCase(data[index].educationMajor);
        // string dataKey = toLowerCase(key.educationMajor);
        while (index >= 0 && data[index].educationMajor > key.educationMajor) {
            data[index + 1] = data[index];
            --index;
            // dataIndex = toLowerCase(data[index].educationMajor);
            // dataKey = toLowerCase(key.educationMajor);
            // cout << "made it here.\n" ;
        }
        data[index + 1] = key;
    }
}

/**
 * @brief For options one through eight. I decided to use a switch case. Though
 * I had originally wanted to use a pointer for the datatobecompare, I ended up
 * with this instead. Maybe, if I have time before this is due, I could optimize
 * that switch. But for now, this will do.
 *
 * @param field
 * @param ascending
 */
void GraduateDataManager::bubbleSort(int field, bool ascending) {
    bool madeAswap = true;
    int lastIndex = data.size() - 1;

    while (madeAswap) {
        madeAswap = false;
        for (int count = 0; count < lastIndex; ++count) {
            bool swap = false;
            switch (field) {
            case 1:
            case 2:
                swap = ascending
                           ? (data[count].meanSalary > data[count + 1].meanSalary)
                           : (data[count].meanSalary < data[count + 1].meanSalary);
                break;
            case 3:
            case 4:
                swap = ascending
                           ? (data[count].medianSalary > data[count + 1].medianSalary)
                           : (data[count].medianSalary < data[count + 1].medianSalary);
                break;
            case 5:
            case 6:
                swap = ascending ? (data[count].demographicsAsian >
                                    data[count + 1].demographicsAsian)
                                 : (data[count].demographicsAsian <
                                    data[count + 1].demographicsAsian);
                break;
            case 7:
            case 8:
                swap = ascending ? (data[count].demographicsMinority >
                                    data[count + 1].demographicsMinority)
                                 : (data[count].demographicsMinority <
                                    data[count + 1].demographicsMinority);
                break;
            }
            if (swap) {
                GradEmploymentData temp = data[count];
                data[count] = data[count + 1];
                data[count + 1] = temp;
                madeAswap = true;
            }
        }
        --lastIndex;
    }
}

/**
 * @brief returns a string of all lower case letters. For increased flexability
 * for the typist.
 *
 * @param str
 * @return string
 */
string GraduateDataManager::toLowerCase(const string &str) const {
    string newString = "";
    for (size_t i = 0; i < str.size(); i++) {
        newString.push_back(tolower(str[i]));
    }
    return newString;
}

/**
 * @brief loads the data from the csv to the objects.
 *
 * @param filename
 * @return true
 * @return false
 */
bool GraduateDataManager::loadFromCSV(const string &filename) {
    string line;
    GradEmploymentData employ;
    char delim = ',';
    std::ifstream file(filename);
    if (file.fail()) {
        return false;
    }

    std::getline(file, line, '\n');

    while (file.peek() != EOF) {
        std::getline(file, line, delim);
        employ.demographicsTotal = std::stoi(line); // string to int

        if (file.peek() == '"') {
            file >> delim;
            std::getline(file, employ.educationMajor, '"');
            file >> delim;
        } else {
            std::getline(file, employ.educationMajor, delim);
        }

        std::getline(file, line, delim);
        employ.meanSalary =
            std::stod(line); // string to double, ask if I need the precesion to
                             // only be one decimal place.

        std::getline(file, line, delim);
        employ.medianSalary =
            std::stod(line); // string to double, ask if I need the precesion to
                             // only be one decimal place.

        std::getline(file, line, delim);
        employ.demographicsAsian = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.demographicsMinority = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.demographicsWhite = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.demographicsFemales = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.demographicsMales = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.educationBachelor = std::stoi(line); // string to int

        std::getline(file, line, delim);
        employ.educationDoctorate = std::stoi(line); // string to int

        std::getline(file, line, '\n');
        employ.educationMasters = std::stoi(line); // string to int

        data.push_back(employ);
    }

    return true;
}

/**
 * @brief For menu options 1-8
 * 1. Top 10 Majors with the Highest Mean Salary.
 * 2. Top 10 Majors with the Lowest Mean Salary.
 * 3. Top 10 Majors with the Highest Median Salary.
 * 4. Top 10 Majors with the Lowest Median Salary.
 * 5. What are the Top 5 Majors with the Highest Number of Asians.
 * 6. What are the Top 5 Majors with the Lowest Number of Asians.
 * 7. What are the Top 5 Majors with the Highest Number of Minorities.
 * 8. What are the Top 5 Majors with the Lowest Number of Minorities.
 *
 * @param option
 * @param ascending
 */
void GraduateDataManager::sortByField(int option, bool ascending) {
    bubbleSort(option, ascending);

    // Set up formatting
    cout << std::fixed
         << std::setprecision(2); // Ensure consistent decimal places for doubles
    cout << std::left;            // Set alignment once

    // Print header based on the sorting field
    string fieldName;
    switch (option) {
    case 1:
    case 2:
        fieldName = "Mean Salary";
        break;
    case 3:
    case 4:
        fieldName = "Median Salary";
        break;
    case 5:
    case 6:
        fieldName = "Asian Demographics";
        break;
    case 7:
    case 8:
        fieldName = "Minority Demographics";
        break;
    }

    cout << "Education Major" << std::right << std::setw(34) << fieldName << endl;
    cout << "-----------------------------------------------------" << endl;
    size_t max = option > 4 ? 5 : 10;
    if (!ascending) {
        for (size_t i = 0; i < data.size() && i < max; i++) {
            cout << std::left << std::setw(37) << data[i].educationMajor;

            switch (option) {
            case 1:
                cout << "$ " << data[i].meanSalary;
                break;
            case 3:
                cout << "$ " << data[i].medianSalary;
                break;
            case 5:
                cout << "# " << data[i].demographicsAsian;
                break;
            case 7:
                cout << "# " << data[i].demographicsMinority;
                break;
            }
            cout << endl;
        }
    } else {
        for (size_t i = 0; i < data.size() && i < max; i++) {
            cout << std::left << std::setw(37) << data[i].educationMajor;

            size_t index = i;

            switch (option) {
            case 2:
                cout << "$ " << data[index].meanSalary;
                break;
            case 4:
                cout << "$ " << data[index].medianSalary;
                break;
            case 6:
                cout << "# " << data[index].demographicsAsian;
                break;
            case 8:
                cout << "# " << data[index].demographicsMinority;
                break;
            }
            cout << endl;
        }
    }
    enter();
}

/**
 * @brief For menu option 11
 * 11. Display Information for a Specific Major
 *
 * @param major
 */
void GraduateDataManager::searchMajor(const string &major) {
    insertionSortByMajor();
    size_t index;
    if (binarySearchMajor(major, index)) {
        displayData(index);
    } else {
        cout << "Major not found.\n";
    }
    enter();
}

/**
 * @brief For menu options 9-10
 *
 * @param option
 */
void GraduateDataManager::displayCustomInfo(int option, string major) {
    size_t index;
    insertionSortByMajor();
    if (option == 9) {
        int index = rand() % data.size();
        displayData(index);
    } else if (binarySearchMajor(major, index)) {
        cout << std::left;
        cout << std::setw(10) << "Education Major: " << data[index].educationMajor
             << endl
             << "-----------------------------------------------------" << endl
             << std::setw(37) << "Asian Demographics"
             << (static_cast<double>(data[index].demographicsAsian) /
                 static_cast<double>(data[index].demographicsTotal)) *
                    100
             << "%" << endl
             << std::setw(37) << std::setw(37) << "Minority Demographics"
             << (static_cast<double>(data[index].demographicsMinority) /
                 (static_cast<double>(data[index].demographicsTotal))) *
                    100
             << "%" << endl
             << std::setw(37) << "White Demographics"
             << (static_cast<double>(data[index].demographicsWhite) /
                 (static_cast<double>(data[index].demographicsTotal))) *
                    100
             << "%" << endl
             << endl
             << std::setw(37) << "Female Demographics"
             << (static_cast<double>(data[index].demographicsFemales) /
                 (static_cast<double>(data[index].demographicsTotal))) *
                    100
             << "%" << endl
             << std::setw(37) << "Males Demographics"
             << (static_cast<double>(data[index].demographicsMales) /
                 (static_cast<double>(data[index].demographicsTotal))) *
                    100
             << "%" << endl;
    } else {
        cout << "Major not found.\n";
    }
    enter();
}

/**
 * @brief view all data or specific data.
 *
 */
void GraduateDataManager::displayData(int index) const {
    // Set up formatting
    cout << std::fixed
         << std::setprecision(2); // Ensure consistent decimal places for doubles
    cout << std::left;            // Set alignment once
    if (index < 0) {
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i].demographicsTotal << ", " << data[i].educationMajor
                 << ", " << data[i].meanSalary << ", " << data[i].medianSalary << ", "
                 << data[i].demographicsAsian << ", " << data[i].demographicsMinority
                 << ", " << data[i].demographicsWhite << ", "
                 << data[i].demographicsFemales << ", " << data[i].demographicsMales
                 << ", " << data[i].educationBachelor << ", "
                 << data[i].educationDoctorate << ", " << data[i].educationMasters
                 << endl;
        }
    } else {
        cout << std::setw(10) << "Education Major: " << data[index].educationMajor
             << endl
             << "-----------------------------------------------------" << endl
             << std::setw(37) << "Total Demographics" << "# "
             << data[index].demographicsTotal << endl
             << std::setw(37) << "Mean Salary" << "$ " << data[index].meanSalary
             << endl
             << std::setw(37) << "Median Salary " << "$ "
             << data[index].medianSalary << endl
             << std::setw(37) << "Asian Demographics" << "# "
             << data[index].demographicsAsian << endl
             << std::setw(37) << "Minority Demographics" << "# "
             << data[index].demographicsMinority << endl
             << std::setw(37) << "White Demographics" << "# "
             << data[index].demographicsWhite << endl
             << std::setw(37) << "Female Demographics" << "# "
             << data[index].demographicsFemales << endl
             << std::setw(37) << "Males Demographics" << "# "
             << data[index].demographicsMales << endl
             << std::setw(37) << "Education Bachlor" << "# "
             << data[index].educationBachelor << endl
             << std::setw(37) << "Education Doctorate" << "# "
             << data[index].educationDoctorate << endl
             << std::setw(37) << "Education Masters" << "# "
             << data[index].educationMasters << endl;
    }
}

/**
 * @brief Construct a new Grad Employment Data:: Grad Employment Data object
 *
 */
GradEmploymentData::GradEmploymentData() {
    demographicsTotal = 0;
    educationMajor = "";
    meanSalary = 0.0;
    medianSalary = 0.0;
    demographicsAsian = 0;
    demographicsMinority = 0;
    demographicsWhite = 0;
    demographicsFemales = 0;
    demographicsMales = 0;
    educationBachelor = 0;
    educationDoctorate = 0;
    educationMasters = 0;
}