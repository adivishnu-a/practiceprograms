#include <stdio.h>
int main()
{
    float cm, meter, km;
    printf("Enter length in centimeter: ");
    scanf("%f", &cm);
    meter = cm / 100.0;
    km    = cm / 100000.0;
    printf("Equivalent length in meter = %.2f m", meter);
    printf("\nEquivalent length in kilometer = %.2f km", km);
    return 0;
}