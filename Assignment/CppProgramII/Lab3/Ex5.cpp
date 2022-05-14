/*
 * @Date: 2022-04-29 18:12:30
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-29 18:19:53
 * @FilePath: \Code_exercise\Assignment\CppProgramII\Lab3\Ex5.cpp
 */
#include <iostream>

class Date {
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    ~Date() {}

    void print() const {
        std::cout << year << "-" << month << "-" << day;
    }
private:
    int year, month, day;
};
class FinalTest {
public:
    FinalTest(std::string n, Date t = Date(2014, 1, 1)) : name(n), time(t) {}
    ~FinalTest() {}

    void setDue(Date t) {
        time = t;
    }
    void print() const {
        std::cout << "Title: " << name << std::endl;
        std::cout << "Test Date: ";
        time.print();
        std::cout << std::endl;
    }
private:
    std::string name;
    Date time;
};

int main() {
    FinalTest item1("C++ Test", Date(2014, 6, 2));
    item1.print();
    FinalTest item2("Java");
    item2.print();
    item2.setDue(Date(2014, 6, 10));
    item2.print();

    return 0;
}