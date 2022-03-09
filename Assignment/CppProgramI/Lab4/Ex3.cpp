#include <iostream>
using namespace std;

int main(){
    for(int line = 1; line <= 5; line ++) {
        for(int blank = 5 - line; blank >= 0; blank --)
            cout << " ";
        for(int star = 1; star <= line * 2 - 1; star ++)
            cout << "*";
        cout << endl;
    }
    for(int line = 4; line >= 1; line --) {
        for(int blank = 5 - line; blank >= 0; blank --)
            cout << " ";
        for(int star = 1; star <= line * 2 - 1; star ++)
            cout << "*";
        cout << endl;
    }
    return 0;
}