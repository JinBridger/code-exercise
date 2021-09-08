#include<bits/stdc++.h>
using namespace std;

int t,n,ans,a[1010];

int check() {
    for(int i=2;i<=n;i++)
    if(a[i]<a[i-1]) return 0;
    return 1;
}
void change_odd() {
    for(int i=1;i<=n-2;i+=2)
    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
}
void change_even() {
    for(int i=2;i<=n-1;i+=2)
    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
}
int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        for(int j=1;j<=n;j++) 
            scanf("%d",&a[j]);
        ans=0;
        while(1) {
            if(check()) break;
            if(ans%2) change_even();
            else change_odd();
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}