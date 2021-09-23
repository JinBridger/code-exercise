#include <iostream>
#include <string>
using namespace std;

string binary;
int decimal,length,cur_val = 1;

int main(){
    cin >> binary;
    length = binary.length();
    for(int i = length - 1; i>=0; i--) {
        decimal += (cur_val * (binary[i] - 48));
        cur_val *= 2;
    }
    cout << decimal;
    return 0;
}