/*
 * @Author: JinBridge
 * @Date: 2022-03-09 15:36:39
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-09 15:43:46
 * Copyright (c) 2022 by JinBridge, All Rights Reserved. 
 */
#include <iostream>

class simpleCalculator {
   public:
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        return a / b;
    }
};
int main() {
    double a = 10;
    double b = 20;
    simpleCalculator sc;

    std::cout << "The value of a is: " << a << std::endl;
    std::cout << "The value of b is: " << b << std::endl;

    std::cout << std::endl;

    std::cout << "Adding a and b yields " << sc.add(a, b) << std::endl;
    std::cout << "Subtracting b from a yields " << sc.subtract(b, a) << std::endl;
    std::cout << "Multiply a by b yields " << sc.multiply(a, b) << std::endl;
    std::cout << "Dividing a by b yields " << sc.divide(a, b) << std::endl;

    return 0;
}