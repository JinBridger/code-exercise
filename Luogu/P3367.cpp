#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,m,fa[MAXN];

int find(int x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    fa[find(x)]=find(y);
}
void ask(int x,int y) {
    if(find(x)==find(y)) printf("Y\n");
    else printf("N\n");
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++) {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if(z==1) merge(x,y);
        if(z==2) ask(x,y);
    }
    return 0;
}