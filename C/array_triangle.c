#include<stdio.h>   
#include <stdlib.h> 
int main()
{
    system("cls");
    int i, j, a[5] = {3, 9, 2, 8, 4};
    for(i=4; i>=0; i--)
    {
        for(j=0; j<=i; j++)
        printf("%d", a[j]);
        printf("\n");
    }
}