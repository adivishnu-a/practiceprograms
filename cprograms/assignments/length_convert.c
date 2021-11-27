#include <stdio.h>
int main()
{
   float cm, m, km;
   printf("Enter length in centimetres : ");
   scanf("%f", &cm);
   m = cm / 100.0;
   km = cm / 100000.0;
   printf("Length in metres = %.2f\n", m);
   printf("Length in kilometres = %.4f", km);
   return 0;
}