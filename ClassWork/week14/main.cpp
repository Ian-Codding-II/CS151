#include <iostream>

class Test {
  public:
    void setA(int x) { a = x; }
    static int getA() {
        return a;
    }

    private:
    static int a;
  };

int main() {
  std::cout << Test::getA();
    Test A;
    A.setA(5);
    Test B;

    B = A;
}