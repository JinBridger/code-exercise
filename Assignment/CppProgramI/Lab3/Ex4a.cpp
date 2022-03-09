#include <iostream>
using namespace std;

int main(){
    int number,answer = 1;
    cout << "Please input the number: ";
    cin >> number;
    while(number) {
        answer *= number;
        number --;
    }
    cout << "n! is : " << answer;
    return 0;
}