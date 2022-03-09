/*
 * @Author: JinBridge
 * @Date: 2022-03-09 14:01:58
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-09 14:21:49
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <iostream>

class complex {
   public:
    complex(double real, double imaginary)
        : realPart(real), imaginaryPart(imaginary) {}
    complex() {}
    complex add(complex& c) {
        return complex(realPart + c.realPart, imaginaryPart + c.imaginaryPart);
    }
    complex sub(complex& c) {
        return complex(realPart - c.realPart, imaginaryPart - c.imaginaryPart);
    }
    void print() {
        std::cout << "(" << realPart << ", " << imaginaryPart << ")";
    }
   private:
    double realPart, imaginaryPart;
};
int main() {
    complex a(1, 7);
    complex b(9, 2);
    a.print();
    std::cout << " + ";
    b.print();
    std::cout << " = ";
    a.add(b).print();
    std::cout << std::endl;

    complex c(10, 1);
    complex d(11, 5);
    c.print();
    std::cout << " - ";
    d.print();
    std::cout << " = ";
    c.sub(d).print();
    std::cout << std::endl;
    return 0;
}