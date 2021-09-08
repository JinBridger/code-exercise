#include<cstdio>
#include<cmath>
using namespace std;

int t,k,cl,mn;

int main() {
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&k);
		cl=ceil(sqrt(k));
		mn=cl*cl;
		int rc=1,rr=cl,tp=mn;
		while(tp!=k) {
			tp--;
			if(rc<rr) { rc++;continue; } 
			if(rc>=rr) { rr--;continue; }
		}
		printf("%d %d\n",rr,rc);
	}
	return 0;
}
