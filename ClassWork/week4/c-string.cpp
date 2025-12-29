/**
 * @file c-string.cpp
 * @author Ian Codding II
 * @brief 
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <iostream>

 int main() {
    char first[] = "Ian";
    char last[] = "Codding";

    last[7] = '\n';

    std::cout << last << std::endl;
 }