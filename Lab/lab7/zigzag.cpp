#include <iostream>
#include <string>

using std::cout, std::endl;

void zigzag(int n);

int main()
{
    zigzag(1);	// *
    cout << endl;
    zigzag(2);	// **
    cout << endl;
    zigzag(3);	// <*>
    cout << endl;
    zigzag(4);	// <**>
    cout << endl;
    zigzag(5);	// <<*>>
    cout << endl;
    zigzag(6);	// <<**>>
    cout << endl;
    zigzag(7);	// <<<*>>>
    cout << endl;
    zigzag(8);   // <<<**>>>
    cout << endl;
}

void zigzag(int n){
    if(n < 0){
        throw n;
    }else if(n == 1){
        cout << "*";
    } else if(n == 2){
        cout << "**";
    }else{
        cout << "<";
        zigzag(n-2);
        cout << ">";
    }
}