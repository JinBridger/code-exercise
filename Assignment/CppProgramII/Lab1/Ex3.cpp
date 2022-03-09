/*
 * @Author: JinBridge
 * @Date: 2022-03-09 14:47:50
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-09 15:34:30
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <iostream>
#include <string>

class hugeInteger {
   public:
    hugeInteger(std::string s) {
        s.reserve();
        for(int i = 0; i < s.length(); ++i)
            integer[i] = s[i] - '0';
    }
    hugeInteger(int n = 0) {
        for(int i = 0; n > 0; ++i) {
            integer[i] = (n % 10);
            n /= 10;
        }
    }

    hugeInteger add(const hugeInteger &n) {
        for(int i = 0; i < 40; ++i) {
            integer[i] += n.integer[i];
            if(integer[i] >= 10) {
                integer[i + 1] += (integer[i] / 10);
                integer[i] %= 10;
            }
        }
        return *this;
    }
    hugeInteger add(int m) {
        return add(hugeInteger(std::to_string(m)));
    }
    hugeInteger add(std::string s) {
        return add(hugeInteger(s));
    }

    hugeInteger subtract(const hugeInteger &n) {
        for(int i = 0; i < 40; ++i) {
            integer[i] -= n.integer[i];
        }
        for(int i = 0; i < 40; ++i) {
            if(integer[i] < 0) {
                integer[i + 1] -= 1;
                integer[i] += 10;
            }
        }
        return *this;
    }
    hugeInteger subtract(int m) {
        return subtract(hugeInteger(std::to_string(m)));
    }
    hugeInteger subtract(std::string s) {
        return subtract(hugeInteger(s));
    }
    
    bool isEqualTo(const hugeInteger &n) {
        for(int i = 0; i < 40; ++i)
            if(integer[i] != n.integer[i])
                return false;
        return true;
    }
    bool isNotEqualTo(const hugeInteger &n) {
        return !isEqualTo(n);
    }
    bool isGreaterThan(const hugeInteger &n) {
        for(int i = 39; i >= 0; --i)
            if(integer[i] != n.integer[i])
                return integer[i] > n.integer[i];
        return false;
    }
    bool isLessThan(const hugeInteger &n) {
        if(isEqualTo(n)) return false;
        return !isGreaterThan(n);
    }
    bool isGreaterThanOrEqualTo(const hugeInteger &n) {
        return (isGreaterThan(n) || isEqualTo(n));
    }
    bool isLessThanOrEqualTo(const hugeInteger &n) {
        return (isLessThan(n) || isEqualTo(n));
    }
    bool isZero() {
        for(int i = 0; i < 40; ++i)
            if(!integer[i])
                return false;
        return true;
    }
    void input(std::string s) {
        s.reserve();
        for(int i = 0; i < s.length(); ++i)
            integer[i] = s[i] - '0';
    }
    void output() {
        int i = 39;
        for(; i >= 0; --i)
            if(integer[i])
                break;
        for(; i >= 0; --i)
            std::cout << integer[i];
    }
   private:
    int integer[40] = {0};
};
int main() {
    std::cout << "7654321 + 7891234 = ";
    hugeInteger(7654321).add(7891234).output();
    std::cout << std::endl;

    std::cout << "7891234 - 5 = ";
    hugeInteger(7891234).subtract(5).output();
    std::cout << std::endl;

    if(hugeInteger(7654321).isEqualTo(hugeInteger(7654321)))
        std::cout << "7654321 is equal to 7654321" << std::endl;

    if(hugeInteger(7654321).isNotEqualTo(hugeInteger(7891234)))
        std::cout << "7654321 is not equal to 7891234" << std::endl;

    if(hugeInteger(7891234).isGreaterThan(hugeInteger(7654321)))
        std::cout << "7891234 is greater than 7654321" << std::endl;
    
    if(hugeInteger(5).isLessThan(hugeInteger(7891234)))
        std::cout << "5 is less than 7891234" << std::endl;
    
    if(hugeInteger(5).isLessThanOrEqualTo(hugeInteger(5)))
        std::cout << "5 is less than or equal to 5" << std::endl;

    if(hugeInteger(0).isGreaterThanOrEqualTo(hugeInteger(0))) 
        std::cout << "0 is greater than or equal to 0" << std::endl;
    return 0;
}