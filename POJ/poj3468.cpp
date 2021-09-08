// #include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=1e5+10;
int n,m,x,y,k;
char opt;
long long num[MAXN];
struct node{
    long long l,r,val,tag;
} tree[MAXN*4];

void build(int l,int r,int p) {
    tree[p].l=l;
    tree[p].r=r;
    if(l==r) {
        tree[p].val=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,p*2);
    build(mid+1,r,p*2+1);
    tree[p].val=tree[2*p].val+tree[2*p+1].val;
}
void spread(int p) {
    if(tree[p].tag) {
        tree[2*p].tag+=tree[p].tag;
        tree[2*p+1].tag+=tree[p].tag;
        tree[2*p].val+=tree[p].tag*(tree[2*p].r-tree[2*p].l+1);
        tree[2*p+1].val+=tree[p].tag*(tree[2*p+1].r-tree[2*p+1].l+1);
        tree[p].tag=0;
    }
}
long long ask(int l,int r,int p) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        return tree[p].val;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    long long val=0;
    if(mid+1<=r) val+=ask(l,r,2*p+1);
    if(l<=mid) val+=ask(l,r,2*p);
    return val;
}
void change(int l,int r,int p,int v) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        tree[p].tag+=v;
        tree[p].val+=v*(tree[p].r-tree[p].l+1);
        return;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid+1<=r) change(l,r,2*p+1,v);
    if(l<=mid) change(l,r,2*p,v);
    tree[p].val=tree[2*p].val+tree[2*p+1].val;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++) {
        cin>>opt;
        if(opt=='C') {
            scanf("%d%d%d",&x,&y,&k);
            change(x,y,1,k);
        }
        if(opt=='Q') {
            scanf("%d%d",&x,&y);
            printf("%lld\n",ask(x,y,1));
        }
    }
    return 0;
}