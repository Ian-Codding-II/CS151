/**
 * @file myCode.h
 * @author Ian Codding II
 * @brief declarations
 * @version 0.1
 * @date 2025-09-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef MYCODE_H
#define MYCODE_H

#include <cctype>
#include <cstddef>
#include <iostream>

int const minChoice = 1; // change based on menu amount
int const maxChoice = 7;

void enter();
std::string toLowerCase(const std::string &str);
bool checkNum(int &num);

#endif
