#include <iostream>
#include <vector>

void foo(){
    static int number = 0;

    number++;
    std::cout << "Number = " << number << std::endl;
}
int main(){
    // std::vector<int> * num = new std::vector <int>;
    // (*num).push_back(1);
    // std::cout << (*num)[0] << std::endl;
    // delete num;

    // int *ptr = new int [10];
    // for (size_t i = 0; i < 10; i++){
    //     ptr[i] = 2*i;
    // }
    // for (size_t i = 0; i<10; i++){
    //     std::cout << ptr[i];
    // }
    // std::cout << std::endl;
    // delete [] ptr;

    return 0;
}