#include<stdio.h>
int main()
{
    int d, y, m, w;
    printf("Enter the no. of Days : ");
    scanf("%d", &d);
    w = d/7;
    m = d/30;
    y = d/365;
    printf("\nThe No. of weeks : %d", w);
    printf("\nThe No. of months : %d", m);
    printf("\nThe No. of years : %d", y);
    return 0;
}
