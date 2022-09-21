#include <stdio.h>
int main()
{
    int a=10, b=2, sum, diff, pro, div, rem;
    printf("a = %d, b = %d\n", a, b);
    sum = a+b;
    diff = a-b;
    pro = a*b;
    div = a/b;
    rem = a%b;
    printf("a+b = %d\n", sum);
    printf("a-b = %d\n", diff);
    printf("a*b = %d\n", pro);
    printf("a/b = %d\n", div);
    printf("Remainder of a/b = %d\n", rem);
    return 0;
}