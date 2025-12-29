#include <iostream>
#include <string>

long long count(int n);

int main(int argc, char * argv[]) {

    std::cout << "Number = " << count(std::stoi(argv[1])) << std::endl;

    return 0;
}

long long count(int n){
    long long num = 0;
    for(int i = 0; i < n; i++){
        num += i;
    }

    return num;
}