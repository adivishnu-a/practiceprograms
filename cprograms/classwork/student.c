#include <stdio.h>
int main()
{
    int stuno, m1, m2, m3, total;
    float per;
    char name[25]; //char datatype accepts only 'a' from "abcde", so declared of character array(string)
    printf("Enter student number : ");
    scanf("%d", &stuno);
    printf("Enter student name : ");
    scanf("%s", &name);
    printf("Enter the marks : ");
    scanf("%d, %d, %d", &m1, &m2, &m3); //Example input: 94, 96, 95
    total = m1+m2+m3;
    per=total/3.0;
    printf("\nStudent Number : %d", stuno);
    printf("\nStudent Name : %s", name);
    printf("\n\nMarks in Subject 1 : %d", m1);
    printf("\nMarks in Subject 2 : %d", m2);
    printf("\nMarks in Subject 3 : %d", m3);
    printf("\nTotal marks : %d", total);
    printf("\nPercentage : %f", per);
    return 0;
}