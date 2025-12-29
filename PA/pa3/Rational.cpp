/**
 * @file Rational.cpp
 * @author Ian Codding II
 * @brief Implementations of the .h file
 * @version 0.1
 * @date 2025-09-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Rational.h"

/**
 * @brief Construct a new Rational:: Rational object
 *
 */
Rational::Rational() {
    denominator = 1;
    numerator = 1;
    sign = '/';
}

/**
 * @brief Construct a new Rational:: Rational object
 *
 * @param numer With a desired numerator
 * @param den Ad denomenator
 */
Rational::Rational(int numer, int den) {
    denominator = den;
    numerator = numer;
    sign = '/';
}

/**
 * @brief Construct a new Rational:: Rational object
 *
 * @param value string to numbers
 */
Rational::Rational(const std::string &value) {
    std::string temp;
    std::istringstream num(value);
    std::getline(num, temp, '/');

    numerator = std::stoi(temp);
    sign = '/';
    std::getline(num, temp);
    denominator = std::stoi(temp);
}

/**
 * @brief To cout desired information, I put them in a stream to be shown all at once.
 *
 * @param out
 * @param num
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &out, const Rational &num) {
    out << num.numerator << num.sign << num.denominator;
    return out;
}

/**
 * @brief operator to be used when the = symbol is used.
 *
 * @param num
 */
void Rational::operator=(const Rational &num) {
    numerator = num.numerator;
    denominator = num.denominator;
    sign = num.sign;
}

/**
 * @brief operator to be used when the types are to be connverted to double
 *
 * @return double
 */
Rational::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

/**
 * @brief Adds two fractions
 *
 * @param lhs
 * @param rhs
 * @return Rational
 */
Rational operator+(const Rational &num, const Rational &num2) {
    int newNum = num.numerator * num2.denominator + num2.numerator * num.denominator;
    int newDen = num.denominator * num2.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Subtracts two fractions
 *
 * @param num
 * @param num2
 * @return Rational
 */
Rational operator-(const Rational &num, const Rational &num2) {
    int newNum = num.numerator * num2.denominator - num2.numerator * num.denominator;
    int newDen = num.denominator * num2.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Multiply to fractions
 *
 * @param num
 * @param num2
 * @return Rational
 */
Rational operator*(const Rational &num, const Rational &num2) {
    int newNum = num.numerator * num2.numerator;
    int newDen = num.denominator * num2.denominator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief Divide two fractions
 * 
 * @param num 
 * @param num2 
 * @return Rational 
 */
Rational operator/(const Rational &num, const Rational &num2) {
    int newNum = num.numerator * num2.denominator;
    int newDen = num.denominator * num2.numerator;
    Rational temp(newNum, newDen);
    temp.reduce();
    return temp;
}

/**
 * @brief This function will simplify the fraction.
 *
 */
void Rational::reduce() {
    for (int i = 2; i < denominator; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
            i = 1;
        }
    }
    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
}