#include <algorithm>
#include <iostream>
#include <vector>
struct Student {
    std::string name;
    int id;
    Student(std::string n, int num) {
        name = n;
        id = num;
    }
};
int main() {
    std::vector<Student> v;
    v.emplace_back("Tom", 123);
    v.emplace_back("Sam", 456);
    v.emplace_back("Jill", 789);
    sort(v.begin(), v.end(),[](Student x, Student b){return x.name < b.name;});
    for (auto student : v) {
        std::cout << student.name << " " << student.id << "\n";
    }
    return 0;
}