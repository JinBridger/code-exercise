#include<bits/stdc++.h>
using namespace std;

int t,k,jud[110],isok;
string s;

int main() {
    scanf("%d",&t);
    for(int i=2;i<=99;i++) {
        for(int j=2;j<i;j++) {
            if(i%j==0) {
                jud[i]=1;
            }
        }
    }
    for(int i=1;i<=t;i++) {
        scanf("%d",&k);
        cin>>s;
        isok=0;
        for(int j=0;j<k;j++) {
            if(s[j]=='1'||s[j]=='4'||s[j]=='6'||s[j]=='8'||s[j]=='9') {
                printf("1\n%c\n",s[j]);
                isok=1;break;
            }   
        }
        if(!isok){
        for(int j=1;j<k;j++) {
            for(int m=0;m<j;m++) {
                if(jud[(s[m]-48)*10+s[j]-48]) {
                    printf("2\n%c%c\n",s[m],s[j]);
                    isok=1;break;
                }
            }if(isok) break;
        }}
    }
    return 0;
}