#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

class NumberArray {
  public:
    NumberArray(int size = 0, double initValue = 0);
    // default constructor
    // TODO: Create Copy Constructor
    NumberArray(const NumberArray &t);

    ~NumberArray() {
        if (arraySize > 0)
            delete[] arr;
    }
    void print() const;
    void setValue(double value);

  private:
    double *arr;
    int arraySize;
};

#endif