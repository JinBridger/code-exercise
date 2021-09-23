#include <iostream>
using namespace std;

int counter,number,largest;

int main(){
    counter = 1;
    while(counter <= 10) {
        counter ++;
        cin >> number;
        if(number > largest) {
            largest = number;
        }
    }
    cout << largest << endl;
    return 0;
}