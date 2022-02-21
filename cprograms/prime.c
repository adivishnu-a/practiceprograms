//Program to check whether the given number is prime number or not
#include <stdio.h>
int main()
{
    int i, n, c=0;
    printf("Enter any number : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        c=c+1;
    }
    if(c==2)
    printf("The Given number is a prime number");
    else
    printf("The given number is NOT a prime number");
    return 0;
}