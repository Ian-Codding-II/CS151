#include "display.h"
#include "person.h"
#include <iostream>
#include <string>

std::string allupper(std::string str);

void recur(int n);

int main() {
    // std::string line;
    // std::cout << "Give me a word and I will return the word in all uppercase\n";
    // std::getline(std::cin, line);
    // line = allupper(line);

    // std::cout << line << std::endl;

    // Person p1("Mike", 32);

    // display(p1);

    recur(3);

    std::cout << std::endl;

    return 0;
}

void recur(int n) {
    if (n <= 1) {
        std::cout << n;
    } else {
        std::cout << n << " = (";
        recur(n / 2 + n % 2);
        std::cout << " , ";
        recur(n / 2);
        std::cout << ")";
    }
}

std::string allupper(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}