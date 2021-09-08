#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int n,m,tmp,ways[MAXN];

int main() {
    scanf("%d%d",&n,&m);
    ways[1]=tmp=1;
    for(int i=2;i<=n;i++) {
        ways[i]=tmp;
        for (int l=2,r;l<=i;l=r+1) {
			r = min(i,i/(i/l));
			ways[i] = (1ll*ways[i]+1ll*(r-l+1)*ways[i/l])%m;
		}
        tmp=(ways[i]+1ll*tmp)%m;
    }
    printf("%d",ways[n]);
    return 0;
}