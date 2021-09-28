#include <iostream>
using namespace std;

int main(){
    int counter = 1,number,largest = 0;   
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