#include <iostream>
using namespace std;

double answer = 1,x,cur_x;
int accuracy,cur_val = 1,counter = 1;

int main(){
    cout << "Please input the accuracy of e: ";
    cin >> accuracy;
    cout << "Please input x:";
    cin >> x;
    cur_x = x;
    while(counter <= accuracy) {
        cur_val *= counter;
        answer += (cur_x / cur_val);
        counter ++;
        cur_x *= x;
    }
    cout << answer;
    return 0;
}