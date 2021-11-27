#include<stdio.h>  
int main()    
{    
    int a, b;
    printf("Enter the value of a:");
    scanf("%d",&a);
    printf("Enter the value of b:");
    scanf("%d",&b);      
    printf("Before swap a=%d b=%d",a,b);      
    a=a+b;    
    b=a-b;    
    a=a-b;    
    printf("\nAfter swap a=%d b=%d",a,b);    
    return 0;  
}