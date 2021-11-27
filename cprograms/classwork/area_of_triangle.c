#include <stdio.h>
int main()
{
    float b, h, a;
    printf("Enter base of triangle: ");
    scanf("%f",&b);
    printf("Enter the height of triangle: ");
    scanf("%f",&h);
    a = 0.5*b*h;
    printf("Area of Triangle = %f", a);
    return 0;
}
