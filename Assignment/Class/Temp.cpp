#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    a = b = c = d = e = f = 0;
    for (int i = 1; i <= 60000; i++) {
        int roll = rand() % 6 + 1;
        switch (roll) {
            case 1: {
                a++;
                break;
            }
            case 2: {
                b++;
                break;
            }
            case 3: {
                c++;
                break;
            }
            case 4: {
                d++;
                break;
            }
            case 5: {
                e++;
                break;
            }
            case 6: {
                f++;
                break;
            }
            default: {
                break;
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    return 0;
}