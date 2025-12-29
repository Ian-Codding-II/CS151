#include "numberArray.h"

int main() {
    NumberArray num;
    num.print();

    NumberArray Not(5, 1.3);
    Not.print();

    NumberArray Now(Not);
    Now.print();

    return 0;
}