/**
 * @file student.hpp
 * @author Ian Codding II
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #ifndef STUDENT_HPP
 #define STUDENT_HPP
#include <iostream>
#include <cctype>

class Student
{
public:
    // accessers or getters
    std::string getName(){ return mName;}
    double getGPA(){ return mGPA;}
    int getID(){ return mID;} 
    
    //mutators or setters
    Student() : mName("none"), mID(0), mGPA(0.0){
        std::cout << "Default constructer\n";
    }
    Student(std::string name, double gpa, int id);
    bool setName(std::string n);
    bool setID(int id);
    bool setGPA(double GPA);

private:
    void removeEndSpaces(std::string &name);
    bool allAlpha(std::string &n);
    std::string mName;
    int mID;
    double mGPA;
};

 #endif