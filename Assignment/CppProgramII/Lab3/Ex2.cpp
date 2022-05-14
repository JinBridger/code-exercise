/*
 * @Date: 2022-04-29 19:10:39
 * @LastEditors: JinBridge
 * @LastEditTime: 2022-04-29 22:13:05
 * @FilePath: \Code_exercise\Assignment\CppProgramII\Lab3\Ex2.cpp
 */
#include <iostream>
using namespace std;
class MyBase31 {
public:
    int a, b, c;
    MyBase31(int x, int y, int z) :a(x), b(y), c(z)
    {
        cout << "BaseClass31 Object is created !" << endl;
        cout << a << " " << b << " " << c << endl;
    }
    ~MyBase31() { cout << "BaseClass31 Object is destroyed!" << endl; }
};
class MyDerived1 : public MyBase31 {
    MyBase31 a = MyBase31(5, 6, 7);
    int c;
public:
    MyDerived1(int x) : c(x), MyBase31(x, 8, 9)
    {
        cout << "Base Object has been created!" << endl;
        cout << "Member Object has been created! " << a.a << " " << a.b << " "
            << a.c << endl;
        cout << "Derived Object is created!  "<< c << endl;
    }
};
int main()
{
    MyDerived1 b(88);
}
