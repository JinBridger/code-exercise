#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,m,r,tot,cnt;
int MODD,rk[MAXN],head[MAXN];
struct e{
    int to,next;
} edge[MAXN];
struct p{ //存储点的信息
    int val,dep,hson; //权值，深度，重儿子
    int size,fa,top,dfn; //子树大小，父节点，所在重链顶点，DFS 序
} node[MAXN];
struct seg_node{ //存储线段树
    int l,r,sum,add;
} tree[MAXN*4];

void add_edge(int f,int t) { //添加边
    edge[++tot].to=t;
    edge[tot].next=head[f];
    head[f]=tot;
    return;
}
void tree_build(int p,int dep) { //第一次DFS
    node[p].dep=dep;
    node[p].size=1;
    for(int i=head[p];i;i=edge[i].next) {
        if(edge[i].to!=node[p].fa) {
            node[edge[i].to].fa=p;
            tree_build(edge[i].to,dep+1);
            node[p].size+=node[edge[i].to].size;
            if(!node[p].hson||node[edge[i].to].size>node[node[p].hson].size)
                node[p].hson=edge[i].to;
        }
    }
    return;
}
void tree_composition(int p,int top) { //第二次DFS
    node[p].top=top;
    cnt++;
    node[p].dfn=cnt;
    rk[cnt]=p;
    if(!node[p].hson) {return;}
    tree_composition(node[p].hson,top);
    for(int i=head[p];i;i=edge[i].next) {
        if(edge[i].to!=node[p].hson&&
            edge[i].to!=node[p].fa)
            tree_composition(edge[i].to,edge[i].to);
    }
    return;
}
void seg_build(int p,int l,int r) { //建立线段树
    tree[p].l=l;
    tree[p].r=r;
    if(l==r) {tree[p].sum=node[rk[l]].val;return;}
    int mid=(l+r)/2;
    seg_build(2*p,l,mid);
    seg_build(2*p+1,mid+1,r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    return;
}
void push_down(int p) { //线段树标记下传
    if(tree[p].add) {
        tree[2*p].sum=(tree[2*p].sum+tree[p].add*(tree[2*p].r-tree[2*p].l+1))%MODD;
        tree[2*p+1].sum=(tree[2*p+1].sum+tree[p].add*(tree[2*p+1].r-tree[2*p+1].l+1))%MODD;
        tree[2*p].add=(tree[2*p].add+tree[p].add)%MODD;
        tree[2*p+1].add=(tree[2*p+1].add+tree[p].add)%MODD;
        tree[p].add=0;
    }
    return;
}
void seg_add(int p,int l,int r,int v) { //线段树区间修改
    if(l<=tree[p].l&&tree[p].r<=r) {
        tree[p].add=(tree[p].add+v)%MODD;
        tree[p].sum=(tree[p].sum+v*(tree[p].r-tree[p].l+1))%MODD;
        return;
    }
    push_down(p);
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid<r) seg_add(2*p+1,l,r,v);
    if(l<=mid) seg_add(2*p,l,r,v);
    tree[p].sum=(tree[2*p].sum+tree[2*p+1].sum)%MODD;
    return;
}
int seg_ask(int p,int l,int r) { //线段树区间查询
    if(l<=tree[p].l&&tree[p].r<=r) {
        return tree[p].sum;
    }
    push_down(p);
    int ret=0;
    int mid=(tree[p].l+tree[p].r)/2;
    if(mid<r) ret=(ret+seg_ask(2*p+1,l,r))%MODD;
    if(l<=mid) ret=(ret+seg_ask(2*p,l,r))%MODD;
    return ret;
}
void tree_add(int p,int v) { //p 子树上所有点权值 +v
    seg_add(1,node[p].dfn,node[p].dfn+node[p].size-1,v);
    return;
}
int tree_ask(int p) { //查询 p 子树所有点权值之和
    return seg_ask(1,node[p].dfn,node[p].dfn+node[p].size-1);
}
int route_ask(int x,int y) { //两点间最短距离上的点值求和
    int ret=0;
    while(node[x].top!=node[y].top) {
        if(node[node[x].top].dep<node[node[y].top].dep)
            swap(x,y);
        ret=(ret+seg_ask(1,node[node[x].top].dfn,node[x].dfn))%MODD;
        x=node[node[x].top].fa;
    }
    if(node[x].dep>node[y].dep)
        swap(x,y);
    ret=(ret+seg_ask(1,node[x].dfn,node[y].dfn))%MODD;
    return ret;
}
void route_change(int x,int y,int v) { //两点间最短距离上的点值修改
    while(node[x].top!=node[y].top) {
        if(node[node[x].top].dep<node[node[y].top].dep)
            swap(x,y);
        seg_add(1,node[node[x].top].dfn,node[x].dfn,v);
        x=node[node[x].top].fa;
    }
    if(node[x].dep>node[y].dep)
        swap(x,y);
    seg_add(1,node[x].dfn,node[y].dfn,v);
    return;
}
void debug(int x) {
    if(x>=10) printf("%d ",x);
    else printf("%d  ",x);
    return;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&r,&MODD);
    for(int i=1;i<=n;i++) {
        scanf("%d",&node[i].val);
    }
    for(int i=1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    tree_build(r,1);
    tree_composition(r,r);
    seg_build(1,1,n);
    for(int i=1;i<=m;i++) {
        int opt,x,y,z;
        scanf("%d",&opt);
        if(opt==1) {scanf("%d%d%d",&x,&y,&z);route_change(x,y,z);}
        if(opt==2) {scanf("%d%d",&x,&y);printf("%d\n",route_ask(x,y));}
        if(opt==3) {scanf("%d%d",&x,&z);tree_add(x,z);}
        if(opt==4) {scanf("%d",&x);printf("%d\n",tree_ask(x));}
    }
    /*
    printf("\nname:  ");
    for(int i=1;i<=n;i++) debug(i);
    printf("\ndep:   ");
    for(int i=1;i<=n;i++) debug(node[i].dep);
    printf("\nDFN:   ");
    for(int i=1;i<=n;i++) debug(node[i].dfn);
    printf("\nsize:  ");
    for(int i=1;i<=n;i++) debug(node[i].size);
    printf("\nfa:    ");
    for(int i=1;i<=n;i++) debug(node[i].fa);
    printf("\ntop:   ");
    for(int i=1;i<=n;i++) debug(node[i].top);
    printf("\nvalue: ");
    for(int i=1;i<=n;i++) debug(seg_ask(1,node[i].dfn,node[i].dfn));
    */
    return 0;
}
/*
19 0 1 99999
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
1 2
2 3
3 4
3 5
5 6
1 7
7 8
8 9
9 10
10 11
10 12
8 13
7 18
18 19
1 14
14 15
15 16
15 17
*/