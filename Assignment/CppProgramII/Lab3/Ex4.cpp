/*
 * @Date: 2022-04-29 19:10:47
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-29 22:54:03
 * @FilePath: \Code_exercise\Assignment\CppProgramII\Lab3\Ex4.cpp
 */
#include <iostream>
using namespace std;

class MyBase {
    int x;
public:
    MyBase(int a) :x(a) {}
    int getX() {return x; }
};
class MyDerived : public MyBase {
    int y;
public:
    MyDerived(int a) : MyBase(a + 4),y(a) {}
    int getY() { return y; }
};
int main()
{
    MyBase a(2), * p = &a;
    MyDerived b(4), * q = &b;
    MyBase& c = a;
    MyBase& d = b;
    cout << a.getX() << " " << p->getX() << endl;
    cout << b.getY() << " " << q->getY() << b.getX() << " " << q->getX() << endl;
    a = b;
    p = q;
    cout << c.getX() << " " << d.getX()  << endl;
    cout << b.getX() << " " << b.getY() << endl;
}
