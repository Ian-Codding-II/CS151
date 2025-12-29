/**
 * @file operators.cpp
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-08
 *
 * @copyright Copyright (c) 2025
 *
 */

class OpClass {
  public:
    OpClass operator+(const OpClass &right);

  private:
    int x;
};

OpClass OpClass::operator+(const OpClass &r) {
    OpClass sum;
    sum.x = this->x + r.x;
    return sum;
}

int main(){
    OpClass d;
    

    return 0;
}