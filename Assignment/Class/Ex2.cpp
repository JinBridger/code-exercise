#include <bits/stdc++.h>
using namespace std;

int a, n, ans = 1;

int main(){
    cin >> a >> n;
    for(int i = 1; i <= n; i++) {
        ans *= a;
    }    
    cout << ans;
    return 0;
}