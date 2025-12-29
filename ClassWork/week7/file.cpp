#include <iostream>
#include <fstream>

int main(){
    std::fstream file1("test", std::ios::out | std::ios::binary);
    std::fstream file2("text.txt", std::ios::out);
    if(!file1 || !file2){
        std::cerr << "Error opening file\n";
        exit(1);
    }
    // int num = 7;
    std::string num = "10000";
    file2 << num;
    file1.write(reinterpret_cast<char *>(&num), sizeof(int));
    file1.close();
    file2.close();

    return 0;
}
