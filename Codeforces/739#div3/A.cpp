#include<cstdio>
using namespace std;

const int MAXN=1010;
int t,k,num[MAXN];

int main() {
	int u=1,v=1;
	while(u<=1000) {
		while((v%3==0)||(v%10==3)) v++;
		num[u]=v;
		u++;v++;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&k);
		printf("%d\n",num[k]);
	}
	return 0;
}
