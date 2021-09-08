#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e6+10;
int n,Y[MAXN];
long long ans;
struct sqr{
    long long x1,y1,x2,y2;
} cube[MAXN];
struct scanline{
    long long x,y1,y2,jud;
} line[MAXN];
struct node{
    int l,r,sum,cov;
} tree[MAXN*4];

void build(int p,int l,int r) {
    tree[p].l=l;tree[p].r=r;
    if(l==r) return;
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    return;
}
void pushup(int p) {
    if(tree[p].cov) {
        tree[p].sum=Y[tree[p].r+1]-Y[tree[p].l];
    } else {
        tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    }
}
void upd_tree(int p,int y1,int y2,int v) {
    if(Y[tree[p].r+1]<=y1||y2<=Y[tree[p].l])
        return;
    if(y1<=Y[tree[p].l]&&Y[tree[p].r+1]<=y2) {
        tree[p].cov+=v;
        pushup(p);
        return;
    }
    upd_tree(2*p,y1,y2,v);
    upd_tree(2*p+1,y1,y2,v);
    pushup(p);
    return;
}
int cmp(scanline a,scanline b) {
    return a.x<b.x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        cube[i]=(sqr){a,b,c,d};
        line[2*i-1]=(scanline){a,b,d,1};
        line[2*i]=(scanline){c,b,d,-1};
        Y[2*i-1]=b;
        Y[2*i]=d;
    }
    sort(line+1,line+1+2*n,cmp);
    sort(Y+1,Y+1+2*n);
    Y[0]=unique(Y+1,Y+1+2*n)-Y-1;
    build(1,1,Y[0]-1);
    for(int i=1;i<2*n;i++) {
        upd_tree(1,line[i].y1,line[i].y2,line[i].jud);
        ans+=tree[1].sum*(line[i+1].x-line[i].x);
        //printf("\n***%d***\n",tree[1].sum);
    }
    printf("%lld",ans);
    //for(int i=1;i<=Y[0];i++) printf("\n%d ",Y[i]);
    return 0;
}