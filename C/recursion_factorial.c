#include <stdio.h>
int fact(int n);
void main()
{
    int n, f;
    printf("Enter any number : ");
    scanf("%d", &n);
    f=fact(n);
    printf("The factorial of the given number = %d", f);
}
int fact(int n)
{
    if(n==0)
    return 1;
    else if(n==1)
    return 1;
    else
    return (n*fact(n-1));
}