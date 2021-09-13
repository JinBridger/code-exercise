#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+1e4;
int n,m,tot,num[MAXN],root[MAXN];
struct node{
    int lson,rson,l,r,val;
} tree[MAXN*20];

int build(int l,int r) {
    int p=++tot;
    tree[p].l=l;
    tree[p].r=r;
    if(l==r) {
        tree[p].val=num[l];
        return p;
    }
    int mid=(l+r)/2;
    tree[p].lson=build(l,mid);
    tree[p].rson=build(mid+1,r);
    return p;
}
int change(int las,int pos,int v) {
    int p=++tot;
    tree[p].l=tree[las].l;
    tree[p].r=tree[las].r;
    if(tree[p].l==tree[p].r) {
        tree[p].val=v;
        return p;
    }
    int mid=(tree[p].l+tree[p].r)/2;
    if(pos>mid) {
        tree[p].lson=tree[las].lson;
        tree[p].rson=change(tree[las].rson,pos,v);
    } else {
        tree[p].rson=tree[las].rson;
        tree[p].lson=change(tree[las].lson,pos,v);
    }
    return p;
}
int ask(int p,int pos) {
    if(tree[p].l==tree[p].r) {
        return tree[p].val;
    }
    int mid=(tree[p].l+tree[p].r)/2;
    if(pos<=mid) return ask(tree[p].lson,pos);
    else return ask(tree[p].rson,pos);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    root[0]=build(1,n);
    for(int i=1;i<=m;i++) {
        int ver,opt,loc,value;
        scanf("%d%d%d",&ver,&opt,&loc);
        if(opt==1) {
            scanf("%d",&value);
            root[i]=change(root[ver],loc,value);
        }
        if(opt==2) {
            root[i]=root[ver];
            printf("%d\n",ask(root[ver],loc));
        }
    }
    return 0;
}