#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=1e5+10;
int n,w,h,ans;
struct Scanline{
    int x,y,yh,val;
} line[MAXN*2];
struct node{
    int l,r,tag,dat;
} tree[MAXN*4];

int cmp(Scanline a,Scanline b) {
    return a.x<b.x;
}
void build(int p,int l,int r) {
    tree[p].l=l;tree[p].r=r;
    if(l==r) return;
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    return;
}
void spread(int p) {
    if(tree[p].tag!=0) {
        tree[2*p].dat+=tree[p].tag;
        tree[2*p+1].dat+=tree[p].tag;

        tree[2*p].tag=tree[2*p+1].tag=tree[p].tag;
        tree[p].tag=0;
    }
}
void change(int p,int l,int r,int v) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        tree[p].dat+=v;
        tree[p].tag+=v;
        return;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(l<=mid) change(2*p,l,r,v);
    if(mid<r) change(2*p+1,l,r,v);
    tree[p].dat=max(tree[2*p].dat,tree[2*p+1].dat);
}
int main(){
    while(scanf("%d%d%d",&n,&w,&h)==3) {
        for(int i=1;i<=n;i++) {
            int x,y,b;
            scanf("%d%d%d",&x,&y,&b);
            line[2*i-1]=Scanline{x,y,y+h-1,b};
            line[2*i]=Scanline{x+w,y,y+h-1,-b};
        }
        ans=0;
        sort(line+1,line+2*n+1,cmp);
        for(int i=1;i<=2*n;i++) {
            change(1,line[i].y,line[i].yh,line[i].val);
            ans=max(ans,tree[1].dat);
        }
    }
    return 0;
}