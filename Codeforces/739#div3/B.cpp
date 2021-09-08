#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int t,a,b,c,num,spc;

int main() {
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d%d%d",&a,&b,&c);
		spc=abs(a-b);
		num=spc*2;
		if(a>num||b>num||c>num||spc<min(a,b)) {
			printf("-1\n");
			continue;
		}
		if(c<=spc) printf("%d\n",c+spc);
		else printf("%d\n",c-spc);
	}
	return 0;
}
