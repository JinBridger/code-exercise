// Project3.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Rectangle.h"
using namespace std;

int getRandom() {
    return rand() % 8 + 2;
}
int main(){
    srand(time(0));
    Rectangle arr[6];
    int ans = 1;
    for(int i = 1; i <= 5; ++i) {
        arr[i].setLength(getRandom());
        arr[i].setWidth(getRandom());
    }
    for(int i = 1; i <= 5; ++i) {
        cout << "Rect " << i << ": ";
        arr[i].print();
        cout << endl;
        if(arr[i].area() > arr[ans].area())
            ans = i;
    }
    cout << "The area of No. " << ans << " rectangle is the largest.";
    return 0;
}