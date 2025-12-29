/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "linkedList.hpp"
using namespace std;

void displayList(const LinkedList &l);

int main() {
    LinkedList list;
    list.add(2.5);
    list.add(7.9);
    list.add(12.6);
    displayList(list);
    cout << '\n';
    return 0;
}

void displayList(const LinkedList &l){
    cout << l.toString() << endl;
}