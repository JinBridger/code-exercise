#include<bits/stdc++.h>
using namespace std;
const int MAXN=200100;
int ori[MAXN<<1];
int aft[MAXN<<1];
int root[MAXN<<1];
int aftlen,n,m,tot;
struct SegmentTree {
	int lc,rc;
	int dat;
} tree[MAXN<<5];

int cmp(int a,int b) {
	return a<b;
}
void prefix() {
	sort(ori+1,ori+n+1);
	aftlen=unique(ori+1,ori+n+1)-ori-1;
}
int build(int l,int r) {
	int p=++tot;
	if(l==r)return p;
	int mid=(l+r)>>1;
	tree[p].lc=build(l,mid);
	tree[p].rc=build(mid+1,r);
	return p;
}
int update(int las,int val,int l,int r) {
	int p=++tot;
	tree[p].lc=tree[las].lc;
	tree[p].rc=tree[las].rc;
	tree[p].dat=tree[las].dat+1;
	if(l!=r) {
		int mid=(l+r)>>1;
		if(val<=mid)tree[p].lc=update(tree[las].lc,val,l,mid);
		else tree[p].rc=update(tree[las].rc,val,mid+1,r);
	}
	return p;
}
int query(int u,int v,int l,int r,int k) {
	if(l==r)return ori[l];
	int mid=(l+r)>>1;
	int cnt=tree[tree[v].lc].dat-tree[tree[u].lc].dat;
	if(cnt>=k)return query(tree[u].lc,tree[v].lc,l,mid,k);
	else return query(tree[u].rc,tree[v].rc,mid+1,r,k-cnt);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&ori[i]);
		aft[i]=ori[i];
	}
	prefix();
	root[0]=build(1,aftlen);
	for(int i=1; i<=n; i++) {
		int tem=lower_bound(ori+1,ori+1+aftlen,aft[i])-ori;
		root[i]=update(root[i-1],tem,1,aftlen);
	}
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",query(root[a-1],root[b],1,aftlen,c));
	}
	return 0;
}