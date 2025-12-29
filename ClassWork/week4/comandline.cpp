/**
 * @file comandline.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-09-10
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
int main(int argc, char *argv[]) {
    std::cout << "This program was called with " << argc << " arguments\n";
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << '\n';
}