#include <stdio.h>
int main()
{
    int a, b, c, max;
    printf("Enter the a number: ");
    scanf("%d",&a);
    printf("Enter the another number: ");
    scanf("%d",&b);
    printf("Enter the another number: ");
    scanf("%d",&c);
    max = a>b?(a>c?a:c):(b>c?b:c);
    printf("The largest number out of these is: %d", max);
    return 0;
}