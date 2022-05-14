/*
 * @Date: 2022-04-29 19:10:43
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-29 22:39:41
 * @FilePath: \Code_exercise\Assignment\CppProgramII\Lab3\Ex3.cpp
 */
#include <iostream>
using namespace std;

class MyBase {
public:
    void f1() { cout << "MyBase f1-----!" << endl; }
    void f2() { cout << "MyBase f2-----!" << endl; }
};
class MyDerived : public MyBase {
public:
    void f2() { cout << "MyDerived f2-----!" << endl; }
    void f22() { MyBase::f2(); cout << "MyDerived f2-----!" << endl; }
    void f3() { cout << "MyDerived f3-----!" << endl; }
};
int main()
{
    MyDerived a;
    a.f1(); a.f2(); a.f3(); a.f22();
}
