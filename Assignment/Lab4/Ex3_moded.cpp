#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Please input the lines of diamond: ";
    cin >> n;
    for(int line = 1; line <= n / 2 + 1; line ++) {
        for(int blank = n / 2 + 1 - line; blank >= 0; blank --)
            cout << " ";
        for(int star = 1; star <= line * 2 - 1; star ++)
            cout << "*";
        cout << endl;
    }
    for(int line = n / 2; line >= 1; line --) {
        for(int blank = n / 2 + 1 - line; blank >= 0; blank --)
            cout << " ";
        for(int star = 1; star <= line * 2 - 1; star ++)
            cout << "*";
        cout << endl;
    }
    return 0;
}