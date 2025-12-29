#include <iostream>
#include <string>

int main ()
{
    std::string str1 = "Hello";
    std::string str2 = "Hellz";

    std::cout << "The comparision is " << str1.compare(str2) << std::endl;

    return 0;
}