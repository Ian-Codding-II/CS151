/**
 * @file   main.cpp
 * @author Ian Codding II
 * @brief  This function tests the circula linked list class
 * @date   WRITE DATE TODAY
 *
 */
#include "circularLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // Part I
    CircularLinkedList ducks;
    ducks.add(1);
    ducks.add(2);
    ducks.add(3);
    ducks.add(4);
    ducks.add(5);
    // ducks.displayList();
    // cout <<endl;
    // ducks.remove(5);
    // ducks.remove(3);
    // ducks.remove(1);
    // ducks.remove(2);
    // ducks.remove(4);
    // ducks.remove(5);
    // ducks.displayList();
    // cout <<endl;

    // Part II
    ducks.eatTheDuck(3);

    // ducks.add(1);
    // ducks.add(2);
    // ducks.add(3);
    // ducks.add(4);
    // ducks.add(5);
    // ducks.eatTheDuck(2);

    // ducks.eatTheDuck(4);

    // ducks.add(1);
    // ducks.add(2);
    // ducks.add(3);
    // ducks.add(4);
    // ducks.add(5);
    // ducks.eatTheDuck(7);

    // ducks.add(1);
    // ducks.add(2);
    // ducks.add(3);
    // ducks.add(4);
    // ducks.add(5);
    // ducks.eatTheDuck(39);

    // ducks.add(1);
    // ducks.add(2);
    // ducks.add(3);
    // ducks.add(4);
    // ducks.add(5);
    // ducks.eatTheDuck(9);

    return 0;
}
