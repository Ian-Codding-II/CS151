/**
 * @file student.cpp
 * @author Ian Codding II
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "student.hpp"
#include <cctype>
#include <cstddef>

bool Student::setName(std::string n){
    //checks if name is 50 charecters or less
    if(n.length() > 50){
        return false;
    }
    //check if it has only
    if(allAlpha(n)){
        mName = n;
        return true;
    }
    return false;
}

bool Student::setID(int id){
    if(id > 0){
        mID = id;
        return true;
    }
    return false;
}

bool Student::setGPA(double GPA){
    if(GPA >= 0.0 && GPA <=4.0){
        mGPA = GPA;
        return true;
    }
    return false;
}

bool Student::allAlpha(std::string &n){
    removeEndSpaces(n);
    for(size_t i = 0; i < n.length(); i++){
        if (!std::isalpha(n[i]) && n[i] != ' '){
            if (i !=0 && n[i-1] == ' ') {
                return false;
            }
            return false;
        }
    }
    return true;
}

void Student::removeEndSpaces(std::string &name){
    int iter = name.size()-1;
    while (name[iter] == ' ')
    {
        iter--;
        name.pop_back();
    }
}

Student::Student(std::string name, double gpa, int id){
    
}