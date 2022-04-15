/*
 * @Author: JinBridge
 * @Date: 2022-04-06 17:54:46
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-10 15:53:10
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

class RationalNumber {
    friend bool operator==(const RationalNumber&, const RationalNumber&);
    friend bool operator!(const RationalNumber&);
    friend bool operator!=(const RationalNumber&, const RationalNumber&);
    friend bool operator<(const RationalNumber&, const RationalNumber&);
    friend bool operator>(const RationalNumber&, const RationalNumber&);
    friend bool operator<=(const RationalNumber&, const RationalNumber&);
    friend bool operator>=(const RationalNumber&, const RationalNumber&);
    friend RationalNumber operator+(const RationalNumber&,
                                    const RationalNumber&);
    friend RationalNumber operator-(const RationalNumber&,
                                    const RationalNumber&);
    friend RationalNumber operator*(const RationalNumber&,
                                    const RationalNumber&);
    friend RationalNumber operator/(const RationalNumber&,
                                    const RationalNumber&);

   public:
    RationalNumber(int N = 0, int D = 1) {
        if (D == 0) {
            std::cerr << "Denominator couldn't be zero!" << std::endl;
            std::cerr << "\tDenominator has been reseted to 1" << std::endl;

            D = 1;
        }
        numerator = N;
        denominator = D;
        reduction();
    }
    RationalNumber(const RationalNumber& n)
        : numerator(n.numerator), denominator(n.denominator) {}

    void printRational() {
        std::cout << numerator;
        if (denominator == 1)
            return;
        std::cout << "/" << denominator;
    }

   private:
    int numerator, denominator;
    int getGCD(int a, int b) { return b > 0 ? getGCD(b, a % b) : a; }
    void reduction() {
        if (numerator == 0) {
            denominator = 1;
        } else {
            int gcd = getGCD(abs(numerator), abs(denominator));
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    }
};
bool operator==(const RationalNumber& a, const RationalNumber& b) {
    if (a.numerator == b.numerator && a.denominator == b.denominator)
        return true;
    else
        return false;
}
bool operator!(const RationalNumber& a) {
    return !a.numerator;
}
bool operator!=(const RationalNumber& a, const RationalNumber& b) {
    return !(a == b);
}
bool operator<(const RationalNumber& a, const RationalNumber& b) {
    int aNumerator = a.numerator * b.denominator;
    int bNumerator = b.numerator * a.denominator;
    return aNumerator < bNumerator;
}
bool operator>(const RationalNumber& a, const RationalNumber& b) {
    if (a == b)
        return false;
    return !(a < b);
}
bool operator<=(const RationalNumber& a, const RationalNumber& b) {
    return (a < b) || (a == b);
}
bool operator>=(const RationalNumber& a, const RationalNumber& b) {
    return (a > b) || (a == b);
}
RationalNumber operator+(const RationalNumber& a, const RationalNumber& b) {
    RationalNumber nA(a), nB(b);
    RationalNumber res(nA);
    res.denominator *= nB.denominator;
    res.numerator *= nB.denominator;
    res.numerator += (nB.numerator * nA.denominator);
    res.reduction();
    return res;
}
RationalNumber operator-(const RationalNumber& a, const RationalNumber& b) {
    RationalNumber res(a);
    res.denominator *= b.denominator;
    res.numerator *= b.denominator;
    res.numerator -= (b.numerator * a.denominator);
    res.reduction();
    return res;
}
RationalNumber operator*(const RationalNumber& a, const RationalNumber& b) {
    RationalNumber res(a.numerator * b.numerator,
                       a.denominator * b.denominator);
    res.reduction();
    return res;
}
RationalNumber operator/(const RationalNumber& a, const RationalNumber& b) {
    RationalNumber res(a.numerator * b.denominator,
                       a.denominator * b.numerator);
    res.reduction();
    return res;
}
int main() {
    RationalNumber c(7, 3), d(3, 9), x;
    c.printRational();
    std::cout << " + ";
    d.printRational();
    std::cout << " = ";
    x = c + d;  // test overloaded operators + and =
    x.printRational();
    std::cout << '\n';
    c.printRational();
    std::cout << " - ";
    d.printRational();
    std::cout << " = ";
    x = c - d;  // test overloaded operators - and =
    x.printRational();
    std::cout << '\n';
    c.printRational();
    std::cout << " * ";
    d.printRational();
    std::cout << " = ";
    x = c * d;  // test overloaded operators * and =
    x.printRational();
    std::cout << '\n';
    c.printRational();
    std::cout << " / ";
    d.printRational();
    std::cout << " = ";
    x = c / d;  // test overloaded operators / and =
    x.printRational();
    std::cout << '\n';
    c.printRational();
    std::cout << " is:\n";
    // test overloaded greater than operator
    std::cout << ((c > d) ? " > " : " <= ");
    d.printRational();
    std::cout << " according to the overloaded > operator\n";
    // test overloaded less than operator
    std::cout << ((c < d) ? " < " : " >= ");
    d.printRational();
    std::cout << " according to the overloaded < operator\n";
    // test overloaded greater than or equal to operator
    std::cout << ((c >= d) ? " >= " : " < ");
    d.printRational();
    std::cout << " according to the overloaded >= operator\n";
    // test overloaded less than or equal to operator
    std::cout << ((c <= d) ? " <= " : " > ");
    d.printRational();
    std::cout << " according to the overloaded <= operator\n";
    // test overloaded equality operator
    std::cout << ((c == d) ? " == " : " != ");
    d.printRational();
    std::cout << " according to the overloaded == operator\n";
    // test overloaded inequality operator
    std::cout << ((c != d) ? " != " : " == ");
    d.printRational();
    std::cout << " according to the overloaded != operator" << std::endl;
    return 0;

    return 0;
}