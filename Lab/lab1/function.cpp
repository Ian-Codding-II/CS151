/**
 * @file function.cpp
 * @author Ian Codding II
 * @brief All the functions
 * @version 0.1
 * @date 2025-08-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "function.hpp"

/**
 * @brief Displays the vector in a set format.
 *
 * @param vec
 */
void displayVector(const std::vector<Team> &vec) {
  std::cout << "   Team name             Number of wins\n"
            << "-------------------------------------------\n";
  std::cout << std::left;
  for (long unsigned i = 0; i < vec.size(); i++) {
    std::cout << std::setw(30) << vec[i].name << " " << vec[i].numWins
              << std::endl;
  }
}

/**
 * @brief search file and update the vector of structures acordingly.
 *
 * @param file
 * @param vec
 */
void searchFile(std::ifstream &file, std::vector<Team> &vec) {
  std::string line;
  while (std::getline(file, line)) {
    bool find = false;
    for (long unsigned i = 0; i < vec.size(); i++) {
      if (vec[i].name == line) {
        vec[i].numWins++;
        find = true;
        break;
      }
    }
    if (!find) {
      Team temp(line);
      vec.push_back(temp);
    }
  }
}

/**
 * @brief Sort the vector based on the number of wins a structure has.
 *
 * @param vec
 */
void sort(std::vector<Team> &vec) {

  int size = vec.size();
  for (int startScan = 1; startScan < size; startScan++) {
    Team key = vec[startScan];
    int index = startScan - 1;
    while (index >= 0 && vec[index].numWins < key.numWins) {
      vec[index + 1] = vec[index];
      --index;
    }
    vec[index + 1] = key;
  }
}

/**
 * @brief puts the data into winners.csv
 *
 * @param out
 * @param vec
 */
void putFile(std::ofstream &out, std::vector<Team> &vec) {
  out << "Team name, Number of wins\n";
  for (long unsigned i = 0; i < vec.size(); i++) {
    out << vec[i].name << "," << vec[i].numWins
              << std::endl;
  }
}
