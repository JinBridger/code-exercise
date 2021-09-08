#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
pair<int,int> lev[MAXN];
int t,n,k,ans,tmp[MAXN],chk[MAXN];

bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.first<b.first;
}
int jud(int p) {
    for(int i=1;i<=n;i++) {
        if(p<lev[i].first) return 0;
        p+=lev[i].second;
    }
    return 1;
}
void src(int lt,int rt) {
    if(lt==rt) {
        ans=lt; return;  
    } 
    if(jud((lt+rt)/2)) {
        src(lt,(lt+rt)/2);
    } else {
        src((lt+rt)/2+1,rt);
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&k);
            for(int p=1;p<=k;p++)
                scanf("%d",&tmp[p]);
            int cur=tmp[1]+1;
            lev[i].first=tmp[1]+1;
            for(int p=1;p<=k;p++) {
                if(cur<=tmp[p]) {
                    cur=tmp[p]+1;
                    lev[i].first=tmp[p]+2-p;
                }
                else cur++;
            }
            lev[i].second=k;
        }
        sort(lev+1,lev+n+1,cmp);
        src(1,1e9+7);
        printf("%d\n",ans);
    }
    return 0;
}