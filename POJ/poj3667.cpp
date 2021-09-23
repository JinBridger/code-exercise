#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=5e5+10;
int n,m;
struct node{
    int l,r,sum,lr,rr,tag; 
    // lr代表从最左数有多少个房间，rr代表从最右数
} tree[MAXN*4];

void build(int p,int l,int r) {
    tree[p].tag=0;
    tree[p].l=l;
    tree[p].r=r;
    if(l==r) {
        tree[p].lr=tree[p].rr=1;
        tree[p].sum=1;
        return ;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].lr=tree[p].rr=tree[p].sum;
    return;
}
void spread(int p) {
    if(tree[p].tag==1) { // rest_in
        tree[2*p].rr=tree[2*p].lr=tree[2*p].sum=0;
        tree[2*p+1].rr=tree[2*p+1].lr=tree[2*p+1].sum=0;
        tree[2*p].tag=tree[2*p+1].tag=1;
    }
    if(tree[p].tag==2) { // get_out
        tree[2*p].rr=tree[2*p].lr=tree[2*p].sum=tree[2*p].r-tree[2*p].l+1;
        tree[2*p+1].rr=tree[2*p+1].lr=tree[2*p+1].sum=tree[2*p+1].r-tree[2*p+1].l+1;
        tree[2*p].tag=tree[2*p+1].tag=2;
    }
    tree[p].tag=0;
}
int ask(int p,int x) {
    spread(p);
    if(tree[p].l==tree[p].r)
        return tree[p].l;
    if(tree[2*p].sum>=x)
        return ask(2*p,x);
    if(tree[2*p].rr+tree[2*p+1].lr>=x)
        return (tree[p].l+tree[p].r)/2-tree[p*2].rr+1;
    else
        return ask(2*p+1,x);
}
void upd(int p) {
    if(tree[2*p].sum==tree[2*p].r-tree[2*p].l+1) {
        tree[p].lr=tree[2*p].sum+tree[2*p+1].lr;
    } else tree[p].lr=tree[2*p].lr;
    if(tree[2*p+1].sum==tree[2*p+1].r-tree[2*p+1].l+1) {
        tree[p].rr=tree[2*p+1].sum+tree[2*p].rr;
    } else tree[p].rr=tree[2*p+1].rr;
    tree[p].sum=max(max(tree[2*p].sum,tree[2*p+1].sum),tree[2*p].rr+tree[2*p+1].lr);
}
void change(int val,int p,int x,int y) {
    spread(p);
    if(x<=tree[p].l&&tree[p].r<=y) {
        if(val==1) // 住进去
            tree[p].sum=tree[p].lr=tree[p].rr=0;
        if(val==2) // 搬出来
            tree[p].sum=tree[p].lr=tree[p].rr=tree[p].r-tree[p].l+1;
        tree[p].tag=val;
        return;
    }
    int mid=(tree[p].l+tree[p].r)/2;
    if(y>mid) change(val,2*p+1,x,y);
    if(x<=mid) change(val,2*p,x,y);
    upd(p);
    return ;
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++) {
        int opt;scanf("%d",&opt);
        if(opt==1) {
            int x;scanf("%d",&x);
            if(tree[1].sum>=x) {
                int k=ask(1,x);
                printf("%d\n",k);
                change(1,1,k,k+x-1);
            } else printf("0\n");
        }
        if(opt==2) {
            int x,y;scanf("%d%d",&x,&y);
            change(2,1,x,x+y-1);
        }
    }
    return 0;
}