#include <iostream>
using namespace std;

int main() {
    int flag[1010];
    for(int i = 1; i <= 1000; ++ i)
        flag[i] = 1;
    for(int i = 2; i <= 1000; ++ i) {
        for(int j = 2; j * i <= 1000; ++ j)  {
            flag[j * i] = 0;
        }
    }
    for(int i = 2; i <= 1000; ++ i) {
        if(flag[i]) cout << i << "\t";
    }
    return 0;
}