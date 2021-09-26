#include <iostream>
using namespace std;

int n, num[1010];
int minnum = 9999999, maxnum;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        minnum = min(num[i], minnum);
        maxnum = max(num[i], maxnum);
    }
    cout << maxnum - minnum;
    return 0;
}