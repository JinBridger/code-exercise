#include <iostream>
using namespace std;

int count,value,total;

int main(){
    cout << "Enter integers (9999 to end):" << endl;
    while(1) {
        cin >> value;
        if(value == 9999)
            break;
        total += value;
        count ++;
    }
    if(count != 0) {
        cout << "The average is: " << total / double(count) << endl;
    } else {
        cout << "No values were entered." << endl;
    }
    return 0;
}