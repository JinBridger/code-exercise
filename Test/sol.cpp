#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=10010;
struct node
{
    int a,b,sum,len,f,num;
    bool l,r;
    node* x,*y;
}*d,ld[MAX*4];
struct Node
{
    int s,t,x,f;
}e[MAX];
int dx[MAX];
int t=0,n,l=0,ls=0,top=1;
bool cmp(const Node &a,const Node &b)
{
    return a.x<b.x||(a.x==b.x&&a.s<b.s);
}
void build(node *&d,int a,int b)
{
    int mid=(a+b)>>1;
    t++;d=&ld[t];
    d->a=a;d->b=b;d->f=0;
    d->sum=0;d->num=0;d->len=dx[b]-dx[a];
    d->l=false;d->r=false;
    if(b-a==1)return;
    build(d->x,a,mid);build(d->y,mid,b);
}
void get_len(node *&d)
{
    if(d->f>0)
    {
        d->sum=d->len;
        return;
    }
    if(d->b-d->a>1)
    {
        d->sum=d->x->sum+d->y->sum;
        return;
    }
    d->sum=0;
}
void get_num(node *&d)
{
    if(d->f>0)
    {
        d->l=true;d->r=true;d->num=1;
    }
    else if(d->b-d->a>1)
    {
        d->l=d->x->l;d->r=d->y->r;
        d->num=d->x->num+d->y->num-d->x->r*d->y->l;
    }
    else
    {
        d->l=false;d->r=false;d->num=0;
    }
}
void change(node *&d,int a,int b,int f)
{
    int mid=(d->a+d->b)>>1;
    if(d->a==a&&d->b==b)
    {
        d->f+=f;
        get_len(d);
        get_num(d);
        return;
    }
    if(b<=mid)
    {
        change(d->x,a,b,f);
    }
    else if(a>=mid)
    {
        change(d->y,a,b,f);
    }
    else
    {
        change(d->x,a,mid,f);
        change(d->y,mid,b,f);
    }
    get_len(d);
    get_num(d);
}
int main()
{
    freopen("D:\\Code_exercise\\Test\\Data\\data.in", "r", stdin);
    freopen("D:\\Code_exercise\\Test\\Data\\data.ans", "w", stdout);
    scanf("%d",&n);
    for(int i=1,a,b,c,d;i<=n;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        dx[i*2-1]=b;dx[i*2]=d;
        e[i*2].s=b;e[i*2-1].s=b;
        e[i*2].t=d;e[i*2-1].t=d;
        e[i*2].x=c;e[i*2-1].x=a;
        e[i*2].f=-1;e[i*2-1].f=1;
    }
    sort(dx+1,dx+n*2+1);
    sort(e+1,e+n*2+1,cmp);
    for(int i=2;i<=2*n;i++)
    {
        if(dx[i]!=dx[top])
        {
            top++;dx[top]=dx[i];
        }
    }
    build(d,1,top);
    for(int i=1,a,b;i<2*n;i++)
    {
        a=lower_bound(dx+1,dx+top+1,e[i].s)-dx;
        b=lower_bound(dx+1,dx+top+1,e[i].t)-dx;
        change(d,a,b,e[i].f);
        l=l+abs(d->sum-ls);
        l=l+d->num*2*(e[i+1].x-e[i].x);
        ls=d->sum;
    }
    int a,b;
    a=lower_bound(dx+1,dx+top+1,e[2*n].s)-dx;
    b=lower_bound(dx+1,dx+top+1,e[2*n].t)-dx;
    change(d,a,b,e[2*n].f);
    l=l+abs(d->sum-ls);
    printf("%d",l);
    return 0;
}