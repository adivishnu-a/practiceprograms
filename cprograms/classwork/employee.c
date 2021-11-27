#include <stdio.h>
int main()
{
    int eno;
    float basic, hra, da, gross, tax, np;
    char ename[25];
    printf("Enter the Employee number : ");
    scanf("%d", &eno);
    printf("Enter the Employee name : ");
    scanf("%s", &ename);
    printf("Enter the basic salary : ");
    scanf("%f", &basic);
    printf("Enter the hra : ");
    scanf("%f", &hra);
    printf("Enter the da : ");
    scanf("%f", &da);
    gross=basic+hra+da;
    tax = gross*0.05;
    np=gross-tax;
    printf("\nEmployee Name : %s", ename);
    printf("\nEmployee Number : %d", eno);
    printf("\nGross Salary = %.2f", gross);
    printf("\nNet Pay = %.2f", np);
    return 0;
}