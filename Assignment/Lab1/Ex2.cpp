#include <cstdio>
#include <iostream>
using namespace std;

int num1,num2,num3;

int main(){
    printf("Input three different integers: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    printf("Sum is %d\n",num1+num2+num3);
    printf("Average is %d\n",(num1+num2+num3)/3);
    printf("Product is %d\n",num1*num2*num3);
    printf("Smallest is %d\n",min(min(num1,num2),num3));
    printf("Largest is %d",max(max(num1,num2),num3));
    return 0;
}