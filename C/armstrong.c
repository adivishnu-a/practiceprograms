#include<stdio.h>  
int main()    
{    
    int n,r,sum=0,temp;    
    printf("Enter the number : ");    
    scanf("%d",&n);    
    temp=n;    
    while(n>0)    
    {    
        r=n%10;    
        sum=sum+(r*r*r);    
        n=n/10;    
    }    
    if(temp==sum)    
    printf("The Given number is an Armstrong number");    
    else    
    printf("The Given number is NOT an Armstrong number");    
    return 0;
}