#include <cstdio>
#include <iostream>
using namespace std;

int num;

int main(){
    printf("Enter a five-digit integer: ");
    scanf("%d",&num);
    printf("%d ",num/10000);
    printf("%d ",(num%10000)/1000);
    printf("%d ",(num%1000)/100);
    printf("%d ",(num%100)/10);
    printf("%d ",num%10);
    return 0;
}