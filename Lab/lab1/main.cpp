/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief Displaying the teams info to the user
 * @version 0.1
 * @date 2025-08-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "function.hpp"
#include <fstream>

int main() {
  std::vector<Team> teams;
  std::ifstream file("WorldSeriesWinners.txt");
  // 1. Check if file opened successfully, if not exit the program
  if (file.fail()) {
    std::cout << "\nError opening file, shuting down. \n\n";
    exit(1);
  }

  // In this assignment, you will need to read a file WorldSeriesWinners.txt
  // into a vector of structures.
  searchFile(file, teams);

  // This file contains a chronological list of World Series' winning teams from
  // 1950 through 2014. The first line in the file is the name of the team that
  // won in 1950, and the last line is the name of the team that won in 2014.
  // (Note that the World Series was not played in 1994) .

  // In this assignment, you will read the file into a vector. After reading
  // each name, you will check if the name exists in the vector. If it does, you
  // will update the number of wins for the team. If it does not, you will push
  // a new object at the end of the vector.

  // Display the vector.
  displayVector(teams);

  // Sort the vector in descending order. You may use any algorithm you choose.
  sort(teams);
  // Display the vector again.
  std::cout << "\n\n################Sorted vector################\n\n";
  displayVector(teams);
  // Write the resulting vector to the file winners.csv. The file should look
  // like this
  std::ofstream teamfin("winners.csv");
  putFile(teamfin, teams);
  
  file.close();
  teamfin.close();

  return 0;
}