#include <fstream>
#include <iostream>
#include <string>

using std::cout, std::endl;

void reverseLines(std::ifstream &file);

int main() {
    std::ofstream outFile("poem.txt");
    outFile << "Roses are red,\n"
            << "Violets are blue.\n"
            << "All my base\n"
            << "Are belong to you.\n";

    std::ifstream inFile("poem.txt");

    reverseLines(inFile);
}

void reverseLines(std::ifstream &file) {
    std::string line;
    if (getline(file, line)) {
        reverseLines(file);
        cout << line << std::endl;
    }
}