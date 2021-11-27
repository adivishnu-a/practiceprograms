#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    printf("Enter any integer : ");
    scanf("%d", &a);
    printf("\nSquare of the number : %.2f", pow(a,2));
    printf("\nCube of the number : %.2f", pow(a,3));
    return 0;
}