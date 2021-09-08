#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int t,a,b,sum,d,e,ans;
int p[1010];

int main() {
    scanf("%d",&t);
    for (int i=1;i<=t;i++) {
        scanf("%d%d",&a,&b);
        if(a<b) swap(a,b);
        sum=a+b;
        if(sum%2==0) {
            printf("%d\n",b+1);
            for(int j=(a-b)/2;j<=(a+3*b)/2;j+=2)
            printf("%d ",j);
            printf("\n");
        } else  {
            printf("%d\n",2*b+2);
            for(int j=(a-b)/2;j<=(a+3*b)/2+1;j++)
            printf("%d ",j);
            printf("\n");
        }
    }
    return 0;
}