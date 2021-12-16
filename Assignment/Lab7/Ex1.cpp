#include <iostream>
using namespace std;

int main() {
    int num[21], counter = 1;
    cout << "Enter 20 integers between 10 and 100: " << endl;
    while(counter <= 20) {
        int flag = 1;
        cin >> num[counter];
        if(num[counter] < 10 || num[counter] > 100) {
            cout << "Invalid number." << endl;
            flag = 0;
        }
        for(int j = 1; j < counter; ++ j) {
            if(num[counter] == num[j]) {
                cout << "Duplicate number." << endl;
                flag = 0;
            }
        }
        if(flag) 
            counter ++;
    }
    cout << endl << "The nonduplicate values are: " << endl;
    for(int i = 1; i <= 20; ++ i)
        cout << num[i] << " ";
    return 0;
}