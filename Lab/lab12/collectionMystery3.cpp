/**
 * @file collectionMystery3.cpp
 * @author Ian Codding II
 * @brief This function stores all the odds in a queue 
 *     and the evens in a stack
 * @version 0.1
 * @date 2025-11-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <queue>
#include <stack>
#include <string>

void collectionMystery3(std::queue<int> &q);

// Here are some example calls:
int main() {

    std::deque<int> dq = {1, 2, 3, 4, 5, 6};
    std::queue<int> q(dq);
    collectionMystery3(q);
    return 0;
}

void collectionMystery3(std::queue<int> &q) {
    std::stack<int> s;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int n = q.front();
        q.pop();
        if (n % 2 == 0) {
            s.push(n);
        } else {
            q.push(n);
        }
    }
    std::cout << "q=" << q.back() << std::endl;
    std::cout << "s=" << s.top() << std::endl;
}