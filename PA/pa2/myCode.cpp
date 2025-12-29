/**
 * @file myCode.cpp
 * @author Ian Codding II
 * @brief I use these functions a lot. so I am just going to include them here
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "myCode.h"

/**
 * @brief I feel this takes care of most errors that can happen before someone
 * presses enter. Which is why I dont just do cin.get.
 *
 */
void enter() {
    std::string input = "";
    std::cout << "\nPress enter to continue...";
    std::getline(std::cin, input);

    return;
}

/**
 * @brief returns a string of all lower case letters. For increased flexability
 * for the typist.
 *
 * @param str
 * @return string
 */
std::string toLowerCase(const std::string &str) {
    std::string newString = "";
    for (size_t i = 0; i < str.size(); i++) {
        newString.push_back(tolower(str[i]));
    }
    return newString;
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

    std::string input;
    bool flaged = false;
    int n = '0';

    std::getline(std::cin, input);
    for (size_t i = 0; i < input.size(); i++) {
        if (!std::isdigit(input[i])) {
            flaged = true; // if found then no good
        } else {
            if (i > 0) {
                num = num * 10;
            }
            num = input[i] + num - n;
        }
    }

    if (flaged || num > maxChoice || num < minChoice) {
        return true; // this tells me to go again
    }

    return false;
}