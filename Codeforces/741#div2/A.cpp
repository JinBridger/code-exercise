#include<bits/stdc++.h>
using namespace std;

int t,l,r,ans;

int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d%d",&l,&r);
        /*ans=0;
            for(int k=l;k<=r;k++)
                if(ans<(r%k))
                    ans=r%k;*/
        printf("%d\n",r%(max(r/2+1,l)));
    }
    return 0;
}