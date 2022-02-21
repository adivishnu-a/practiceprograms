#include <stdio.h>
int main()
{
    int a=10, b=20;
    printf("Initially, value of a = %d and value of b = %d", a, b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("\nAfter swapping, value of a = %d and value of b = %d", a, b);
    return 0;
}