#include <iostream>

class A {
  public:
    int aaa = 3;
    A() { std::cout << "A is created\n"; }
    ~A() { std::cout << "A is killed\n"; }

  protected:
    int aa = 2;

  private:
    int a = 1;
};

class B : public A {
  public:
    B() { std::cout << "B is created\n"; }
    ~B() { std::cout << "B is killed\n"; }

    void print() {
        std::cout << aa << std::endl;
    }
};

int main() {
    // A myA;
    B myB;
    std::cout << myB.aaa << std::endl;

    return 0;
}