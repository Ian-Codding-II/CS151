/**
 * @file switchPairs.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-11-04
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cstddef>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>

// Write a function named switchPairs that takes a reference
// to a stack of integers as a parameter and that switches
// successive pairs of numbers starting at the bottom of the stack.
void switchPairs(std::stack<int> &s);

int main() {
    // For example, if the stack initially stores these values:

    std::deque<int> d = {3, 8, 17, 9, 99, 9, 17, 8, 3, 1, 2, 3, 4, 14};
    std::stack<int> s(d);

    // Your function should switch the first pair (3, 8),
    // the second pair (17, 9), the third pair (99, 9),
    // and so on, yielding this sequence:
    //
    // {8, 3, 9, 17, 9, 99, 8, 17, 1, 3, 3, 2, 14, 4}
    switchPairs(s);

    std::stack<int> temp(s);
    for (size_t i = 0; i < s.size(); i++) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // If there are an odd number of values in the stack,
    // the value at the top of the stack is not moved.
    // For example, if the original stack had stored:
    //
    // {3, 8, 17, 9, 99, 9, 17, 8, 3, 1, 2, 3, 4, 14, 42}

    // It would again switch pairs of values,
    // but the value at the top of the stack (42)
    // would not be moved, yielding this sequence:
    //
    // {8, 3, 9, 17, 9, 99, 8, 17, 1, 3, 3, 2, 14, 4, 42}
}

void switchPairs(std::stack<int> &s) {
    std::queue<int> q;
    int tempTop = 0;
    bool nEven = false;
    int sizeS = s.size();
    if (sizeS % 2 != 0) {
        sizeS--;
        nEven = !nEven;
        tempTop = s.top();
        s.pop();
    }
    for (int i = 0; i < sizeS; i++) {
        q.push(s.top());
        s.pop();
    }
    for (int j = 0; j < sizeS / 2; j++) {
        for (int i = 0; i < sizeS - 2*(j+1); i++) {
            q.push(q.front());
            q.pop();
        }
        s.push(q.front());
        q.pop();
        s.push(q.front());
        q.pop();
    }
    if (nEven) {
        s.push(tempTop);
    }
}