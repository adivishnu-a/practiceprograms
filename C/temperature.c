#include<stdio.h>
int main()
{
    float c1, f1, c2, f2;
    printf("Enter Temp in Celsius : ");
    scanf("%f", &c1);
    f1 = (1.8 * c1) + 32;
    printf("Temperature in Fahrenheit : %.2f ", f1);
    printf("\n\nEnter Temp in Fahrenheit : ");
    scanf("%f", &f2);
    c2 = (f2-32) / 1.8;
    printf("Temperature in Celsius : %.2f ", c2);
    return 0;
}
