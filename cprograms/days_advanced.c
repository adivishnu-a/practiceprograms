#include<stdio.h>
int main()
{
    int input, years, months, weeks, days;
    printf("Enter the no. of Days : ");
    scanf("%d", &input);
    years = input/365;
    input = input - (years*365);
    months = input/30;
    input = input - months*30;
    weeks = input/7;
    input = input - (weeks*7);
    printf("These are equivivalet to %d years %d months %d weeks and %d days", years, months, weeks, input);
    return 0;
}
