#include <stdio.h>
#include <stdlib.h>
void main()
{
    int ia[5], sem[5], class, roll, viva, i, total=0;
    float per;
    char name[25], sec;
    printf("Enter the name : ");
    gets(name);
    printf("Enter the Section : ");
    scanf("%c", &sec);
    printf("Enter the Class : ");
    scanf("%d", &class);
    printf("Enter the Roll Number : ");
    scanf("%d", &roll);
    printf("Enter the internal Assesment marks (out of 30) of :\n");
    for(i=0; i<5; i++)
    {
        printf("Paper %d : ", (i+1));
        scanf("%d", &ia[i]);
    }
    printf("Enter the End Sem Exam marks (out of 100) of :\n");
    for(i=0; i<5; i++)
    {
        printf("Paper %d : ", (i+1));
        scanf("%d", &sem[i]);
    }
    printf("Enter The Viva marks (out of 20) : ");
    scanf("%d", &viva);
    for(i=0; i<5; i++)
    {
        total=total+ia[i]+sem[i];
    }
    total=total+viva;
    per=100*total/((float)670);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n*****************************************************************");
    printf("\n\t\t\tMARKSHEET");
    printf("\n*****************************************************************");
    printf("\nName: %s\t\t\tClass: %d", name, class);
    printf("\nSection: %c\t\t\tRoll No: %d", sec, roll);
    printf("\n*****************************************************************");
    printf("\nPaper\tInternal Assesment\tEnd Sem Exam");
    for(i=0; i<5; i++)
    {
        printf("\nPaper %d\t\t%d\t\t%d", (i+1), ia[i], sem[i]);
    }
    printf("\n*****************************************************************");
    printf("\nViva Marks : %d", viva);
    printf("\n*****************************************************************");
    printf("\nTotal: %d\tPercentage: %.2f\tDivision: ", total, per);
    if(per>=60.0)
    printf("1");
    else if(per<60.0 && per>=50.0)
    printf("2");
    else if(per<50.0 && per>=40.0)
    printf("3");
    else
    printf("FAIL");
    printf("\n*****************************************************************");
    printf("\nResult: ");
    if(per>=40.0)
    printf("PASS");
    else
    printf("FAIL");
    printf("\n*****************************************************************");
}