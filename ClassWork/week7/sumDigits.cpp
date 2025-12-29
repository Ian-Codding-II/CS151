#include <iostream>
#include <string>

int sumDigits(int num);

int main() {
    std::cout << "Enter a digit and I will sum each tenth: ";

    std::string line;
    std::getline(std::cin, line);

    std::cout << sumDigits(std::stoi(line)) << std::endl;

    return 0;
}

int sumDigits(int num) {
    return num < 10 ? num : sumDigits(num / 10) + num % 10;
}