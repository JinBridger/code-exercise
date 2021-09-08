#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
long long n,m,opt,x,y,k;
long long MODD,num[MAXN];
struct node{
    long long l,r,val,add,mlp;
} tree[4*MAXN];

void build(int p,int l,int r) {
    tree[p].l=l;
    tree[p].r=r;
    tree[p].mlp=1;
    if(l==r) {
        tree[p].val=num[l]%MODD;
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].val=(tree[p*2].val+tree[p*2+1].val)%MODD;
}
void spread(int p) {
    tree[p*2].val=(1ll)*((tree[p*2].r-tree[p*2].l+1)*tree[p].add+tree[2*p].val*tree[p].mlp)%MODD;
    tree[p*2+1].val=(1ll)*((tree[p*2+1].r-tree[p*2+1].l+1)*tree[p].add+tree[2*p+1].val*tree[p].mlp)%MODD;

    tree[p*2].add=(1ll)*(tree[p*2].add*tree[p].mlp+tree[p].add)%MODD;
    tree[p*2+1].add=(1ll)*(tree[p*2+1].add*tree[p].mlp+tree[p].add)%MODD;

    tree[p*2].mlp=(1ll)*(tree[p*2].mlp*tree[p].mlp)%MODD;
    tree[p*2+1].mlp=(1ll)*(tree[p*2+1].mlp*tree[p].mlp)%MODD;

    tree[p].add=0;
    tree[p].mlp=1;
}
void add(int p,int l,int r,int v) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        tree[p].add=(tree[p].add+v)%MODD;
        tree[p].val=(tree[p].val+v*(tree[p].r-tree[p].l+1))%MODD;
        return ;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid<r) add(2*p+1,l,r,v);
    if(l<=mid) add(2*p,l,r,v);
    tree[p].val=(1ll)*(tree[2*p].val+tree[2*p+1].val)%MODD;
}
void mlp(int p,int l,int r,int v) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        tree[p].add=(tree[p].add*v)%MODD;
        tree[p].mlp=(tree[p].mlp*v)%MODD;
        tree[p].val=(tree[p].val*v)%MODD;
        return ;
    }
    spread(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid<r) mlp(2*p+1,l,r,v);
    if(l<=mid) mlp(2*p,l,r,v);
    tree[p].val=(1ll)*(tree[2*p].val+tree[2*p+1].val)%MODD;
}
long long ask(int p,int l,int r) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        return tree[p].val;
    }   
    spread(p);
    long long ans=0;
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid<r) ans+=ask(2*p+1,l,r);
    if(l<=mid) ans+=ask(2*p,l,r);
    return ans%MODD;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&MODD);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    build(1,1,n);
    // MODD=0x7fffffff;
    for(int i=1;i<=m;i++) {
        scanf("%lld",&opt);
        if(opt==1) {scanf("%lld%lld%lld",&x,&y,&k);mlp(1,x,y,k);}
        if(opt==2) {scanf("%lld%lld%lld",&x,&y,&k);add(1,x,y,k);}
        if(opt==3) {scanf("%lld%lld",&x,&y);printf("%lld\n",ask(1,x,y));}
    }
    // printf("\n***\n");
    // for(int i=1;i<=n;i++) printf("%d ",ask(1,i,i));
    return 0;
}