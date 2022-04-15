/*
 * @Author: JinBridge
 * @Date: 2022-03-30 16:30:20
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-10 15:48:48
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <algorithm>
#include <iostream>
#include <string>

const int HUGEINT_BIT = 40;  // Adjust class hugeInteger's bitwidth

class HugeInteger {
    friend bool operator==(const HugeInteger&, const HugeInteger&);
    friend bool operator!(const HugeInteger&);
    friend bool operator!=(const HugeInteger&, const HugeInteger&);
    friend bool operator<(const HugeInteger&, const HugeInteger&);
    friend bool operator>(const HugeInteger&, const HugeInteger&);
    friend bool operator<=(const HugeInteger&, const HugeInteger&);
    friend bool operator>=(const HugeInteger&, const HugeInteger&);
    friend HugeInteger operator+(const HugeInteger&, const HugeInteger&);
    friend HugeInteger operator-(const HugeInteger&, const HugeInteger&);
    friend HugeInteger operator*(const HugeInteger&, const HugeInteger&);
    friend HugeInteger operator/(const HugeInteger&, const HugeInteger&);
    friend std::ostream& operator<<(std::ostream&, const HugeInteger&);

   public:
    HugeInteger& operator=(const HugeInteger& a) {
        for (int i = HUGEINT_BIT - 1; i >= 0; --i)
            integer[i] = a.integer[i];
        return *this;
    }

    HugeInteger(std::string s) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); ++i)
            integer[i] = s[i] - '0';
    }
    HugeInteger(int n = 0) {
        for (int i = 0; n > 0; ++i) {
            integer[i] = (n % 10);
            n /= 10;
        }
    }
    int getLength() const {
        for (int i = HUGEINT_BIT - 1; i >= 0; --i) {
            if (!integer[i])
                return i + 1;
        }
        return 0;
    }

   private:
    int integer[HUGEINT_BIT] = {0};

    HugeInteger& getHalf() {
        for (int i = HUGEINT_BIT - 1; i >= 0; --i) {
            if (i)
                integer[i - 1] += (integer[i] % 2) * 10;
            integer[i] /= 2;
        }
        return *this;
    }
};
bool operator==(const HugeInteger& a, const HugeInteger& b) {
    for (int i = 0; i < HUGEINT_BIT; ++i)
        if (a.integer[i] != b.integer[i])
            return false;
    return true;
}
bool operator!(const HugeInteger& a) {
    for (int i = 0; i < HUGEINT_BIT; ++i)
        if (!a.integer[i])
            return false;
    return true;
}
bool operator!=(const HugeInteger& a, const HugeInteger& b) {
    for (int i = 0; i < HUGEINT_BIT; ++i)
        if (a.integer[i] != b.integer[i])
            return true;
    return false;
}
bool operator<(const HugeInteger& a, const HugeInteger& b) {
    for (int i = HUGEINT_BIT - 1; i >= 0; --i)
        if (a.integer[i] != b.integer[i])
            return a.integer[i] < b.integer[i];
    return false;
}
bool operator>(const HugeInteger& a, const HugeInteger& b) {
    for (int i = HUGEINT_BIT - 1; i >= 0; --i)
        if (a.integer[i] != b.integer[i])
            return a.integer[i] > b.integer[i];
    return false;
}
bool operator<=(const HugeInteger& a, const HugeInteger& b) {
    for (int i = HUGEINT_BIT - 1; i >= 0; --i)
        if (a.integer[i] != b.integer[i])
            return a.integer[i] < b.integer[i];
    return true;
}
bool operator>=(const HugeInteger& a, const HugeInteger& b) {
    for (int i = HUGEINT_BIT - 1; i >= 0; --i)
        if (a.integer[i] != b.integer[i])
            return a.integer[i] > b.integer[i];
    return true;
}
HugeInteger operator+(const HugeInteger& a, const HugeInteger& b) {
    HugeInteger c;
    for (int i = 0; i < HUGEINT_BIT; ++i)
        c.integer[i] = a.integer[i] + b.integer[i];
    for (int i = 0; i < HUGEINT_BIT; ++i)
        if (c.integer[i] >= 10) {
            c.integer[i + 1] += c.integer[i] / 10;
            c.integer[i] %= 10;
        }
    return c;
}
HugeInteger operator-(const HugeInteger& a, const HugeInteger& b) {
    HugeInteger c;
    for (int i = 0; i < HUGEINT_BIT; ++i)
        c.integer[i] = a.integer[i] - b.integer[i];
    for (int i = 0; i < HUGEINT_BIT; ++i)
        if (c.integer[i] < 0) {
            c.integer[i + 1]--;
            c.integer[i] += 10;
        }
    return c;
}
HugeInteger operator*(const HugeInteger& a, const HugeInteger& b) {
    HugeInteger res, temp;
    if (!a || !b)
        return HugeInteger(0);
    for (int i = b.getLength() - 1; i >= 0; --i) {
        for (int j = HUGEINT_BIT - 1; j > 0; --j)
            res.integer[j] = res.integer[j - 1];
        res.integer[0] = 0;
        for (int j = 0; j < HUGEINT_BIT; ++j)
            temp.integer[j] = 0;
        for (int j = 0; j < a.getLength(); ++j) {
            temp.integer[j] += a.integer[j] * b.integer[i];
            if (temp.integer[j] >= 10) {
                temp.integer[j + 1] += (temp.integer[j] / 10);
                temp.integer[j] %= 10;
            }
        }
        res = (res + temp);
    }
    return res;
}
HugeInteger operator/(const HugeInteger& a, const HugeInteger& b) {
    // Perform a / b by using binary search
    if (a < b)
        return HugeInteger(0);
    if (a == b)
        return HugeInteger(1);
    HugeInteger lt, rt(a), mid;

    while (lt != rt) {
        mid = (lt + rt).getHalf();
        if (mid * b == a)
            return mid;
        if (mid * b < a) {
            lt = mid + HugeInteger(1);
        } else {
            rt = mid;
        }
    }

    return lt - HugeInteger(1);
}
std::ostream& operator<<(std::ostream& os, const HugeInteger& a) {
    int i = HUGEINT_BIT - 1;
    for (; i >= 0; --i)
        if (a.integer[i])
            break;
    if (i == -1)
        os << 0;
    for (; i >= 0; --i)
        os << a.integer[i];
    return os;
}
int main() {
    std::cout << "n1 is 7654321\nn2 is 7891234\nn3 is 9999999999999999999\nn4 is 1\nn5 is 12341234\nn6 is 7888\nresult is 0\n\n\n";
    if(HugeInteger(7654321) != HugeInteger(7891234))
        std::cout << "n1 is not equal to n2" << std::endl;
    if(HugeInteger(7654321) < HugeInteger(7891234))
        std::cout << "n1 is less than n2" << std::endl;
    if(HugeInteger(7654321) <= HugeInteger(7891234))
        std::cout << "n1 is less than or equal to n2" << std::endl;
    if(HugeInteger(7654321) + HugeInteger(7891234) == HugeInteger(15545555))
        std::cout << "7654321 + 7891234 = 1554555" << std::endl;
    std::cout << std::endl << std::endl;

    if(HugeInteger("9999999999999999999") + HugeInteger(1) == HugeInteger("10000000000000000000"))
        std::cout << "9999999999999999999 + 1 = 10000000000000000000" << std::endl << std::endl;
    
    if(HugeInteger(7654321) + HugeInteger(9) == HugeInteger(7654330))
        std::cout << "7654321 + 9 == 7654330" << std::endl;
    if(HugeInteger(7654321) + HugeInteger(10000) == HugeInteger(7901234))
        std::cout << "7654321 + 10000 == 7901234" << std::endl;
    if(HugeInteger(12341234) * HugeInteger(7888) == HugeInteger("97347653792"))
        std::cout << "12341234 * 7888 == 97347653792" << std::endl;
    if(HugeInteger(12341234) - HugeInteger(7888) == HugeInteger(12333346))
        std::cout << "12341234 - 7888 == 12333346" << std::endl;
    if(HugeInteger(12341234) / HugeInteger(7888) == HugeInteger(1564))
        std::cout << "12341234 / 7888 == 1564" << std::endl;
    
    return 0;
}