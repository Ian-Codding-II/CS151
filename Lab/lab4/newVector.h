/**
 * @file newVector.h
 * @author Ian Codding II
 * @brief
 * @version 0.1
 * @date 2025-09-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef NEWVECTOR_H
#define NEWVECTOR_H

#include "Vector.h"

class newVector : public Vector {
  public:
    newVector();
    newVector(int size);
    ~newVector();
    virtual void print() const;
    void doSomthing(int fill);
};

#endif