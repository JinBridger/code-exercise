#include <iostream>
using namespace std;

int main(){
    int f[50],k;
    f[1] = f[2] = 1;
    for(int i = 3; i <= 49; i++)
        f[i] = f[i-1] + f[i-2];
    cin >> k;
    cout << f[k];
    return 0;
}