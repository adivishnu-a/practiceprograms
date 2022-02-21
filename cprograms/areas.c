#include <stdio.h>
int main()
{
    int l=5, b=3, s=4, as, ar;
    printf("For rectangle: l = %d, b = %d", l, b);
    printf("\nFor square: s = %d", s);
    ar = l*b;
    as = s*s;
    printf("\n\nArea of rectangle = %d", ar);
    printf("\nArea of square = %d", as);
    return 0;
}