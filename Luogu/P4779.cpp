#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int n,m,s,cnt,head[MAXN],vis[MAXN],dis[MAXN];
struct e{
    int to,next,length;
} edge[MAXN];

void add_edge(int f,int t,int l) {
    edge[++cnt].to=t;
    edge[cnt].next=head[f];
    edge[cnt].length=l;
    head[f]=cnt;
}
void dij(int st) {
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,st));
    while(!q.empty()) {
        pair<int,int> cur;
        cur=q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second]=1;
        for(int i=head[cur.second];i;i=edge[i].next) {
            if(dis[edge[i].to]>dis[cur.second]+edge[i].length) {
                dis[edge[i].to]=dis[cur.second]+edge[i].length;
                q.push(make_pair(-dis[edge[i].to],edge[i].to));
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    for(int i=1;i<=n;i++)
        dis[i]=0x7fffffff;
    dis[s]=0;
    dij(s);
    for(int i=1;i<=n;i++) {
        printf("%d ",dis[i]);
    }
    return 0;
}