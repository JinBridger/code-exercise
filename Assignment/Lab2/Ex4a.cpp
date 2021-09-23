#include <iostream>
using namespace std;

int number,answer = 1;

int main(){
    cin >> number;
    while(number) {
        answer *= number;
        number --;
    }
    cout << answer;
    return 0;
}