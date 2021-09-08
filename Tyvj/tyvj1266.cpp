#include<bits/stdc++.h>
using namespace std;

int n,ans,lamp[10][10];

int judge() {
	for(int y=1;y<=5;y++)
		for(int x=1;x<=5;x++)
			if(!lamp[y][x])return 0;
	return 1;
}
void change(int gx,int gy) {
	lamp[gy][gx]=!lamp[gy][gx];
	lamp[gy+1][gx]=!lamp[gy+1][gx];
	lamp[gy-1][gx]=!lamp[gy-1][gx];
	lamp[gy][gx+1]=!lamp[gy][gx+1];
	lamp[gy][gx-1]=!lamp[gy][gx-1];
}
void dfs(int cx,int cy,int stp) {
	if(stp==6) return;
	change(cx,cy);
	if(judge()) {
		ans=min(ans,stp+1);
		change(cx,cy);
		return;
	}
	if(cx==5&&cy==5) {
		change(cx,cy);
		return;
	}
	if(cx==5) dfs(1,cy+1,stp+1);
	else dfs(cx+1,cy,stp+1);
	change(cx,cy);
	if(cx==5) dfs(1,cy+1,stp);
	else dfs(cx+1,cy,stp);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int y=1;y<=5;y++)
			for(int x=1;x<=5;x++)
				scanf("%1d",&lamp[y][x]);/**/
		ans=0x7fffffff;
		if(judge()){
			printf("0\n");continue;
		}
		dfs(1,1,0);
		if(ans!=0x7fffffff) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
