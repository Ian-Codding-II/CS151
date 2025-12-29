#include "display.h"

void display(Person &p) {
    std::cout << "Name: " << p.mName << std::endl
              << "Age: " << p.mAge << std::endl;
}