/**
 * @file function.hpp
 * @author Ian Codding II
 * @brief This is where declare all functions.
 * @version 0.1
 * @date 2025-08-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// The structure will have two member variables teamName and numberOfWins.
struct Team {
  std::string name;
  int numWins;
  Team(std::string n = " ", int wins = 1) {
    name = n;
    numWins = wins;
  }
};
void displayVector(const std::vector<Team> &vec);
void searchFile(std::ifstream &file, std::vector<Team> &vec);
void sort(std::vector<Team> &vec);
void putFile(std::ofstream &out, std::vector<Team> &vec);

#endif // FUNCTIONS_HPP