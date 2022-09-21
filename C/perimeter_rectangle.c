#include <stdio.h>
int main()
{
    int l, b, p;
    printf("Enter the length of rectangle : ");
    scanf("%d", &l);
    printf("Enter the breadth of rectangle : ");
    scanf("%d", &b);
    p = 2*(l+b);
    printf("Perimeter of rectangle = %d", p);
    return 0;
}