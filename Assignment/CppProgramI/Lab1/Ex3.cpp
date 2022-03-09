#include <iostream>
#include <cstdio>
using namespace std;

int num1,num2;

int main(){
    printf("Enter two integers:");
    scanf("%d%d",&num1,&num2);
    if(num1%num2==0)
        printf("%d is a multiple of %d",num1,num2);
    else
        printf("%d is not a multiple of %d",num1,num2);
    return 0;
}