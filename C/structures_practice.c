#include <stdio.h>
#include <string.h>

struct Student{
    int roll, marks;
    char name[30];
}s[30];

struct StuAcc{
    char stuname[30];
    char ch;
    int roomno, busno;
}a[30];

int main()
{
    int i, n, choice;
    printf("Enter the number of students : ");
    scanf("%d", &n);
    printf("\n================================================");
    printf("\nEnter the details of %d students\n", &n);
    printf("================================================");
    for(i=0; i<n; i++)
    {
        printf("\nEnter Details of Student %d", (i+1));
        printf("\nEnter the roll number : ");
        scanf("%d", &s[i].roll);
        printf("Enter the student name : ");
        scanf("\n%[^\n]%*c", &s[i].name);
        strcpy(a[i].stuname, s[i].name);
        printf("Enter the total marks : ");
        scanf("%d", &s[i].marks);
        printf("\nEnter T is transport and H if Hostel : ");
        scanf("%c", &a[i].ch);
        if(a[i].ch=='T' || a[i].ch=='t')
        {
            printf("\nEnter the bus number : ");
            scanf("%d", &a[i].busno);
        }
        else if(a[i].ch=='H' || a[i].ch=='h')
        {
            printf("\nEnter the room number : ");
            scanf("%d", &a[i].roomno);
        }
        printf("\n================================================");

    }
    while(choice != 4)
    {
        
    }
    printf("\n************************************************");
    printf("The Students Details are...\n");
    printf("\n************************************************");
    for(i=0; i<n; i++)
    {
        printf("\nStudent Number %d\n Roll Number : %d", (i+1), s[i].roll);
        printf("\nStudent Name : %s", s[i].name);
        printf("\nTotal Marks : %d", s[i].marks);
        printf("\n************************************************");
    }
}