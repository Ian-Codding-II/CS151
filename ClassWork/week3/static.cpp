#include <iostream>
int *n = new int;

void foo() {
    std::cout << "n = " << *n << std::endl;
    (*n)++;
}

int main() {
    foo();
    foo();
    foo();
    foo();
    foo();
    return 0;
}
