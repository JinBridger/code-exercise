#include <iostream>
using namespace std;

int main() {
    double const_e = 1;
    int accuracy, cur_val = 1, counter = 1;
    cout << "Please input the accuracy of e: ";
    cin >> accuracy;
    while (counter <= accuracy) {
        cur_val *= counter;
        const_e += (1 / (double)cur_val);
        counter++;
    }
    cout << const_e;
    return 0;
}