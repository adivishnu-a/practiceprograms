#include <stdio.h>
int main()
{
    int a, b, c, sum;
    float avg;
    printf("Enter a number : ");
    scanf("%d", &a);
    printf("Enter another number : ");
    scanf("%d", &b);
    printf("Enter another number : ");
    scanf("%d", &c);
    sum = a+b+c;
    avg = sum/3.0;
    printf("\nSum of givenn numbers : %d", sum);
    printf("\nAverage of given numbers : %.2f", avg);
    return 0;
}