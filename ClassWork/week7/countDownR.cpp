#include <iostream>
#include <string>

long long count(int n);

int main(int argc, char *argv[]) {

    std::cout << "Number = " << count(std::stoi(argv[1])) << std::endl;

    return 0;
}

long long count(int n) {
    return n == 0 ? n : count(n - 1) + n - 1;
}