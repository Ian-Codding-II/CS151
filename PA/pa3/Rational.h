/**
 * @file Rational.h
 * @author Ian Codding II
 * @brief Declarations
 * @version 0.1
 * @date 2025-09-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef RATIONAL_H
#define RATIONAL_H
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

class Rational {
  public:
    Rational();
    Rational(int numer, int den);
    Rational(const std::string &value);

    // This will now take a c-style string and force it to use my constructor
    Rational(const char* value) : Rational(std::string(value)) {}

    friend std::ostream &operator<<(std::ostream &out, const Rational &num);

    void operator=(const Rational &num);

    operator double() const;

    friend Rational operator+(const Rational &num, const Rational &num2);

    friend Rational operator-(const Rational &num, const Rational &num2);

    friend Rational operator*(const Rational &num, const Rational &num2);

    friend Rational operator/(const Rational &num, const Rational &num2);


    void reduce();

  private:
    int denominator;
    int numerator;
    char sign;
};

#endif