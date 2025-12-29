#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
  public:
    Person(std::string n = "", int a = 0)
        : mName(n)
        , mAge(a) {}

    friend void display(Person &p);

  private:
    std::string mName;
    int mAge;
};
#endif