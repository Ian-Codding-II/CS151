/**
 * @file checkBalance.cpp
 * @author Ian Codding II
 * @brief Function to farifiy the {} and () have
 *     a close and beginning properly lade out.
 * @version 0.1
 * @date 2025-11-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <stack>
#include <string>

// Write a function named checkBalance that accepts a string
// of source code and uses a stack to check whether the braces/parentheses
// are balanced. Every ( or { must be closed by a } or ) in the opposite order.
// Return the index at which an imbalance occurs, or -1 if the string is balanced.
// If any ( or { are never closed, return the string's length.
int checkBalance(std::string word);

// Here are some example calls:
int main() {

    //    index   0123456789012345678901234567890
    std::cout << checkBalance("if (a(4) > 9) { foo(a(2)); }");       // returns -1 because balanced
    std::cout << checkBalance("for (i=0;i&lt;a(3};i++) { foo{); )"); // returns 14 because } out of order
    std::cout << checkBalance("while (true) foo(); }{ ()");          // returns 20 because } doesn't match any {
    checkBalance("if (x) {");                                        // returns 8 because { is never closed
    // Constraints: Use a single stack as auxiliary storage.

    return 0;
}

int checkBalance(std::string word) {
    // make stack
    std::stack<char> temp;
    for (size_t i = 0; i < word.size(); i++) {
        if (('(' == word[i]) || ('{' == word[i])) {
            // add to stack
            temp.push(word[i]);
        } else if (')' == word[i]) {
            if (temp.empty()) {
                return i;
            }
            // check if top of stack is open '(' and remove it
            if (temp.top() == '(') {
                temp.pop();
            } else { // else order is bad, return the index
                return i;
            }
        } else if ('}' == word[i]) {
            if (temp.empty()) {
                return i;
            }
            // check if top of stack is open '{' and remove it
            if (temp.top() == '{') {
                temp.pop();
            } else { // else order is bad, return the index
                return i;
            }
        }
    }
    if (!temp.empty()) {
        return word.size();
    } else {
        return -1;
    }
}