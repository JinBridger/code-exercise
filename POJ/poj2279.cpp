#include <bits/stdc++.h>
using namespace std;

int n,k[6],f[6][6][6][6][6];

int main(){
    while(1) {
        cin >> n;
        if(!n) break;
        memset(k, 0, sizeof(k));
        memset(f, 0, sizeof(f));
        f[0][0][0][0][0] = 1;
        for(int i = 1; i <= n; ++i)
            cin >> k[i];
        for(int a1 = 0; a1 <= k1[1]; ++a1)
            for(int a2 = 0; a2 <= k[2]; ++a2)
                for(int a3 = 0; a3 <= k[3]; ++a3)
                    for(int a4 = 0; a4 <= k[4]; ++a4)
                        for(int a5 = 0; a5 <= k[5]; ++a5) {
                            if(a1 < k[1])    f[a1 + 1][a2][a3][a4][a5] += f[a1][a2][a3][a4][a5];
                            
                        }
    }
    return 0;
}