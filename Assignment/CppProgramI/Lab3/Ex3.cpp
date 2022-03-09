#include <iostream>
using namespace std;

int main(){
    int answer = 0;
    int binary;
    int cur_bits = 1;
    cin >> binary;
    while(binary) {
        answer += cur_bits * (binary % 10);
        cur_bits *= 2;
        binary /= 10;
    }
    cout << answer;
    return 0;
}