#include <stdio.h>
int main()
{
    int a1, a2, a3;
    printf("Enter the three angles of triangle a1, a2, a3 : ");
    scanf("%d, %d, %d", &a1, &a2, &a3);
    if(a1+a2+a3==180)
    {
        printf("Triangle is possible");
        if(a1==90||a2==90||a3==90)
        printf("\nIt is a Right-Angled Triangle");
        else if(a1>90||a2>90||a3>90)
        printf("\nIt is an Obtuse-Angles Triangle");
        else
        printf("\nIt is an Acute-Angled Triangle");
    }
    else
    {
        printf("Triangle not possible");
    }
    return 0;
}