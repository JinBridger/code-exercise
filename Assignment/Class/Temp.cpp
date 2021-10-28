#include <bits/stdc++.h>
using namespace std;



int main(){
    int b = 10;
    double x = 2.5, z = 1.4, y = 0;
    y=(x = z * b++, b = b * x, b++);
    cout << y << " " << x << " " << b << endl;
    return 0;
}