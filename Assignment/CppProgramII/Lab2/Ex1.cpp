/*
 * @Author: JinBridge
 * @Date: 2022-03-30 15:53:45
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-30 16:28:31
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <iostream>

class complex {
    friend std::istream& operator>>(std::istream&, complex&);
    friend std::ostream& operator<<(std::ostream&, const complex&);
    friend complex operator+(const complex&, const complex&);
    friend complex operator-(const complex&, const complex&);
    friend complex operator*(const complex&, const complex&);
    friend bool operator==(const complex&, const complex&);
    friend bool operator!=(const complex&, const complex&);

   public:
    complex(double real = 0, double imaginary = 0)
        : realPart(real), imaginaryPart(imaginary) {}

   private:
    double realPart, imaginaryPart;
};

std::istream& operator>>(std::istream& is, complex& c) {
    char temp;
    std::cin >> temp >> c.realPart >> temp >> c.imaginaryPart >> temp;
    return is;
}
std::ostream& operator<<(std::ostream& os, const complex& c) {
    os << "(" << c.realPart << ", " << c.imaginaryPart << ")";
    return os;
}
complex operator+(const complex& a, const complex& b) {
    complex c;
    c.realPart = a.realPart + b.realPart;
    c.imaginaryPart = a.imaginaryPart + b.imaginaryPart;
    return c;
}
complex operator-(const complex& a, const complex& b) {
    complex c;
    c.realPart = a.realPart - b.realPart;
    c.imaginaryPart = a.imaginaryPart - b.imaginaryPart;
    return c;
}
complex operator*(const complex& a, const complex& b) {
    complex c;
    c.realPart = a.realPart * b.realPart - a.imaginaryPart * b.imaginaryPart;
    c.imaginaryPart =
        a.realPart * b.imaginaryPart + a.imaginaryPart * b.realPart;
    return c;
}
bool operator==(const complex& a, const complex& b) {
    if (a.imaginaryPart == b.imaginaryPart)
        if (a.realPart == b.realPart)
            return true;
    return false;
}
bool operator!=(const complex& a, const complex& b) {
    if (a.imaginaryPart == b.imaginaryPart)
        if (a.realPart == b.realPart)
            return false;
    return true;
}

int main() {
    complex x, y(4.3, 8.2), z(3.3, 1.1), k;

    std::cout << "Enter a complex number in the form: (a, b)\n? ";
    std::cin >> k;  // demonstrating overloaded >>
    std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k
              << '\n';  // demonstrating overloaded <<
    x = y + z;          // demonstrating overloaded + and =
    std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
    x = y - z;  // demonstrating overloaded - and =
    std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
    x = y * z;  // demonstrating overloaded * and =
    std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
    if (x != k)  // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
    std::cout << '\n';
    x = k;
    if (x == k)  // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
    return 0;

    return 0;
}