/**
 * @file   test.cpp
 * @author Ian Codding II
 * @brief  Implement my own version of the vector that uses
 *         dynamic memory allocation and pointers
 * @date   WRITE DATE TODAY
 *
 */
#include "newVector.h"
#include "Vector.h"

using namespace std;

int main() {
    // Lab5.1
    /*
        cout <<"Creating a vector size 5...\n";
        Vector vect1(5);
        vect1.print();
        cout <<"\nCreating an empty vector...\n";
        Vector vect;
        vect.print();
        for (int i = 1; i <=3; i++)
        {
            cout << "\nPushing an element...\n";
            vect.push_back(i);
            vect.print();
        }

        cout << "\nPopping an element...\n";
        vect.pop_back();
        vect.print();

        cout <<"Setting 1st element to 7...\n";
        vect[0]=7;
        vect.print();
    */
    // Lab 4.2
    newVector myVector;
    myVector.print();
    cout << endl;

    newVector myVector1(5);
    myVector1.print();
    cout << endl;

    Vector * ptr = &myVector1;
    (*ptr).print();
    cout << endl;
    
    newVector fillWithSomthing(5);
    fillWithSomthing.doSomthing(2);
    fillWithSomthing.print();
    cout << endl;

    return 0;
}
