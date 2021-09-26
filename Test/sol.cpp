#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
const int maxm=100005;
struct node{
	int x,y1,y2,val;
}line[maxm*2];
int n,h,w,cnt;
inline bool comp(node a,node b)
{
	if(a.x==b.x) return a.val<b.val; 
    else return a.x<b.x; 
}
struct _Hash{
	int _hash[maxm*2],tot;
	inline void clear(){tot=0;}
	inline void push(int x){_hash[++tot]=x;}
	inline void work(){std::sort(_hash+1,_hash+tot+1);tot=std::unique(_hash+1,_hash+tot+1)-_hash-1;}
	inline int get_id(int x){return std::lower_bound(_hash+1,_hash+tot+1,x)-_hash;}
}H;
struct tree{
	int maxi[maxm*4],tag[maxm*4];
	inline void pushup(int o){maxi[o]=std::max(maxi[(o<<1)],maxi[(o<<1)|1])+tag[o];}
	void build(int o,int l,int r)
	{
		maxi[o]=tag[o]=0;
		if(l>=r) return;
		int mid=(l+r)>>1;
		build((o<<1),l,mid),build((o<<1)|1,mid+1,r);
		pushup(o);
	}
	void change(int o,int l,int r,int ql,int qr,int val)
	{
		if((ql<=l)&&(r<=qr)) 
		{
			maxi[o]+=val;
			tag[o]+=val;
			return;
		}
	    int mid=(l+r)>>1;
	    if(ql<=mid) change((o<<1),l,mid,ql,qr,val);
		if(qr>mid) change((o<<1)|1,mid+1,r,ql,qr,val);
	    pushup(o);
	}
}st;
signed main()
{
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "r", stdin);
    freopen("D:\\Code_exercise\\Test\\Data\\data.ans", "w", stdout);
	while(scanf("%lld%lld%lld",&n,&w,&h)!=EOF)
	{
		H.clear();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,val;
			scanf("%lld%lld%lld",&x,&y,&val);
			line[++cnt]=node{x,y,y+h,val};
			line[++cnt]=node{x+w,y,y+h,-val};
		    H.push(y),H.push(y+h);
		}
		std::sort(line+1,line+cnt+1,comp);
		H.work();
		st.build(1,1,H.tot);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int l=H.get_id(line[i].y1);
			int r=H.get_id(line[i].y2)-1;
			st.change(1,1,H.tot,l,r,line[i].val);
			ans=std::max(ans,st.maxi[1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}