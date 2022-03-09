/*
 * @Author: JinBridge
 * @Date: 2022-03-09 14:22:24
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-03-09 14:46:30
 * Copyright (c) 2022 by JinBridge, All Rights Reserved.
 */
#include <iostream>

class Time {
   public:
    Time(int h, int m, int s, bool AMstate)
        : hour(h), minute(m), second(s), isAM(AMstate) {}
    Time(){};

    Time& tick() {
        ++second;
        if (second >= 60) {
            minute += (second / 60);
            second %= 60;
        }
        if (minute >= 60) {
            hour += (minute / 60);
            minute %= 60;
            if (hour == 12)
                isAM = !isAM;
            else
                hour %= 12;
        }
        return *this;
    }
    void print() {
        if (hour < 10)
            std::cout << 0;
        std::cout << hour << ":";
        if (minute < 10)
            std::cout << 0;
        std::cout << minute << ":";
        if (second < 10)
            std::cout << 0;
        std::cout << second << " ";
        isAM ? (std::cout << "AM") : (std::cout << "PM");
        std::cout << std::endl;
    }

   private:
    int hour, minute, second;
    bool isAM;
};
int main() {
    Time t(11, 59, 56, 0);
    for (int i = 1; i <= 15; ++i)
        t.tick().print();

    return 0;
}