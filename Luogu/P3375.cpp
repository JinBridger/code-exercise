#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+10;
int l1,l2,nxt[MAXN];
char s1[MAXN],s2[MAXN];

void prefix() {
    nxt[1]=0;
    for(int i=2,j=0;i<=l2;i++) {
        while(j>0&&s2[j+1]!=s2[i])
            j=nxt[j];
        if(s2[i]==s2[j+1]) j++;
        nxt[i]=j;
    }
}
void kmp() {
    for(int i=1,j=0;i<=l1;i++) {
        while(j>0&&s1[i]!=s2[j+1])
            j=nxt[j];
        if(s1[i]==s2[j+1]) j++;
        if(j==l2) {
            printf("%d\n",i-l2+1);
            j=nxt[j];
        }
    }
}
int main(){
    cin>>(s1+1);
    cin>>(s2+1);
    l1=strlen(s1+1);
    l2=strlen(s2+1);
    prefix();
    kmp();
    for(int i=1;i<=l2;i++)
        printf("%d ",nxt[i]);
    return 0;
}