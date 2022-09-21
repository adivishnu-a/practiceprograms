#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, d, r1, r2;
    printf("In quadratic equation ax^2 +6 bx + c\nEnter the value of a: ");
    scanf("%f",&a);
    printf("Enter the value of b: ");
    scanf("%f",&b);
    printf("Enter the value of c: ");
    scanf("%f",&c);
    d=sqrt((b*b)-(4*a*c));
    if(d==0)
    {
        r1 = (-b)/(2*a);
        printf("The Roots are real and equal, Root = %.2f", r1);
    }
    else if(d>0)
    {
        r1 = (-b+d)/(2*a);
        r2 = (-b-d)/(2*a);
        printf("The roots are: %.2f and %.2f", r1, r2);
    }
    else
    {
        printf("The roots are imaginary");
    }
    return 0;
}