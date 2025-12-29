/**
 * @file main.cpp
 * @author Ian Codding II
 * @brief Demonstrate a simple library class
 * @date 2024-01-12
 * 
 * 
 */
#include <iostream>
using namespace std;
#include "library.h"


int main()
{
    Library CDA("Cour d'Alene");
    //Add books to the library
    CDA.addBook("The Adventures of Tom Sawyer", "Mark Twain", 4);
    CDA.addBook("A Game of Thrones: A Song of Ice and Fire", "George R.R. Martin", 1);
    CDA.addBook("The Call of the Wild", "Jack London", 4);

    cout<<"***********Books currently at the library:***************\n";
    CDA.displayBooks();

    cout<<"Adding Tom as a customer...\n";
    CDA.addCustomer("Tom Cook");
    cout<<"Adding Tom as a customer again...\n";
    CDA.addCustomer("Tom Cook");
    cout<<"\n###############Tom is getting books...##################\n";
    cout<<"A Game of Thrones: A Song of Ice and Fire...\n";
    CDA.getBook("Tom Cook", "A Game of Thrones: A Song of Ice and Fire");
    cout<<"A Game of Thrones: A Song of Ice and Fire...again...\n";
    CDA.getBook("Tom Cook", "A Game of Thrones: A Song of Ice and Fire");//You already have...
    cout<<"The Adventures of Tom Sawyer...\n";
    CDA.getBook("Tom Cook", "The Adventures of Tom Sawyer");
    cout<<"White Fang...\n";
    CDA.getBook("Tom Cook", "White Fang");//...is not available
    cout<<"\n################List of Tom's books:####################\n";
    CDA.displayBooks("Tom Cook");

    cout<<"\n***********Books currently at the library:***************\n";
    CDA.displayBooks();

    cout<<"Adding Sam as a customer...\n";
    CDA.addCustomer("Sam Miller");
    cout<<"\n###############Sam is getting books...##################\n";
    cout<<"A Game of Thrones: A Song of Ice and Fire...\n";
    CDA.getBook("Sam Miller", "A Game of Thrones: A Song of Ice and Fire");
    cout<<"The Adventures of Tom Sawyer...\n";
    CDA.getBook("Sam Miller", "The Adventures of Tom Sawyer");

    cout<<"\n################List of Sams's books:####################\n";
    CDA.displayBooks("Sam Miller");

    cout<<"\n***********Books currently at the library:***************\n";
    CDA.displayBooks();

    cout<<"\n###############Tom is returning books...##################\n";
    cout<<"A Game of Thrones: A Song of Ice and Fire...\n";
    CDA.returnBook("Tom Cook", "A Game of Thrones: A Song of Ice and Fire");
    cout<<"A Game of Thrones: A Song of Ice and Fire...again...\n";
    CDA.returnBook("Tom Cook", "A Game of Thrones: A Song of Ice and Fire");//You don't have...
    cout<<"White Fang...\n";
    CDA.returnBook("Tom Cook", "White Fang");//...is not available
    cout<<"\n################List of Tom's books:####################\n";
    CDA.displayBooks("Tom Cook");

    cout<<"\n***********Books currently at the library:***************\n";
    CDA.displayBooks();

    cout<<"\n**********Customers currently at the library:*************\n";
    CDA.displayCustomers();

    return 0;
}
