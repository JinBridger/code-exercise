#include<cstdio>
using namespace std;

const int MAXN=50000;
int z,m,h,ans,a[MAXN],b[MAXN],answ[MAXN];

void deal() {
	ans=0;
	for(int t=1;t<=h;t++) {
		answ[t]=1%m;
		for(;b[t];b[t]>>=1) {
			if(b[t]&1) answ[t]=(long long) answ[t]*a[t]%m;
			a[t]=(long long)a[t]*a[t]%m;
		}
		ans+=answ[t];ans%=m;
	}
}
int main() {
	scanf("%d",&z);
	for(int i=1;i<=z;i++) {
		scanf("%d%d",&m,&h);
		for(int u=1;u<=h;u++)
			scanf("%d%d",&a[u],&b[u]);
		deal();
		printf("%d\n",ans);
	}
	return 0;
}
