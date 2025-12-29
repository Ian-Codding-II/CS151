/**
 * @file stutter.cpp
 * @author Ian Codding II
 * @brief This function will duplicate every value in a queue
 * @version 0.1
 * @date 2025-11-04
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cstddef>
#include <queue>
#include <iostream>

// Write a function named stutter that
// accepts a reference to a queue of integers as a parameter
// and replaces every element with two copies of itself.
void stutter(std::queue<int> &q);

int main() {
    // For example, if a queue named q stores {1, 2, 3},
    // the call of stutter(q); should change it to store {1, 1, 2, 2, 3, 3}.
    std::deque<int> dq = {1, 2, 3};
    std::queue<int> q(dq);
    stutter(q);
    std::cout << q.front() << std::endl;
}

void stutter(std::queue<int> &q) {
    std::queue<int> temp = {};
    int sizeQ = q.size();
    for (int i = 0; i < sizeQ; i++) {
        temp.push(q.front());
        temp.push(q.front());
        q.pop();
    }
    int sizeT = temp.size();
    for (int i = 0; i < sizeT; i++) {
        q.push(temp.front());
        temp.pop();
    }
}