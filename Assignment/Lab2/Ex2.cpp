#include <iostream>
using namespace std;

int number,digits[6],counter;

int main(){
    cin >> number;
    counter = 1;
    while(number) {
        digits[counter] = number % 10;
        number /= 10;
        counter++;
    }
    counter = 1;
    if((digits[1] == digits[5]) && (digits[2] == digits[4])) {
        cout << "the five-digit intergers is a palindrome!";
    } else {
        cout << "It is not a palindrome!";
    }
    return 0;
}