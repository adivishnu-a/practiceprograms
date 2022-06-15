#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Program to perform insertion and deletion in a linked list
//By Adi Vishnu Avula - AP21110010186

struct Node{
int stationNumber;
char stationname[30];
float frequency;
struct Node *next;
};
struct Node *createnewnode()
{
    //This is initiated by the main() function at the beginning of the program
    int n; //variable declaration
    struct Node *first,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the station number: ");
    scanf("%d",&first->stationNumber);
    printf("Enter the station name: ");
    fflush(stdin);
    scanf("%s",first->stationname);
    printf("Enter the station frequency: ");
    scanf("%f",&first->frequency);
    printf("\n");
    last=first;
    last->next=NULL;
    printf("\nEnter any number to continue or 0 to stop entering station details");
    printf("\nEnter your choice: ");
    scanf("%d",&n);
    while(n!=0)
    {
        //if the user wants to add more station details
        last->next=(struct Node*)malloc(sizeof(struct Node));
        last=last->next;
        printf("\nEnter the station number: ");
        scanf("%d",&last->stationNumber);
        printf("Enter the station name: ");
        fflush(stdin);
        scanf("%s",last->stationname);
        printf("Enter the station frequency: ");
        scanf("%f",&last->frequency);
        printf("\n");
        last->next=NULL;
        printf("\nEnter any number to continue or 0 to stop entering station details");
        printf("\nEnter your choice : ");
        scanf("%d",&n);
    }
    return first;
}
struct Node *insert_new_node(struct Node *first)
{
    //This is called when the user wants to perform insertion
    char ch;
    printf("\nA. Add a new station at the beginning");
    printf("\nB. Add a new station at a specified position");
    printf("\nC. Add a new station in the end\n");
    printf("\nEnter your choice: ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='A')
    {
        //when the user wants to input a new station at the beginnning
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->next=first;
        printf("\nEnter the station number: ");
        scanf("%d",&temp->stationNumber);
        printf("Enter the station name: ");
        scanf("%s",temp->stationname);
        printf("Enter the station frequency: ");
        scanf("%f",&temp->frequency);
        printf("\n");
        first=temp;
        return first;
    }
    if(ch=='B')
    {
        //when the user wants to add a new station at a specified position
        struct Node *p=first;
        int i;
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        int pos;
        printf("\nEnter the index where you want to enter the new station: ");
        scanf("%d",&pos);
        if(pos==0)
        {
            temp->next=first;
            printf("\nEnter the station number: ");
            scanf("%d",&temp->stationNumber);
            printf("Enter the station name: ");
            scanf("%s",temp->stationname);
            printf("Enter the station frequency : ");
            scanf("%f",&temp->frequency);
            printf("\n");
            first=temp;
        }
        else
        {
            for(i=0;i<pos-1;i++)
            {
                if(p->next==NULL)
                      break;
                p=p->next;
            }
            if(p->next==NULL)
            {
                 p->next=temp;
                 printf("\nEnter the station number: ");
                 scanf("%d",&temp->stationNumber);
                 printf("Enter the station name: ");
                 scanf("%s",temp->stationname);
                 printf("Enter the station frequency : ");
                 scanf("%f",&temp->frequency);
                 printf("\n");
                 temp->next=NULL;
            }
            else
            {
                temp->next=p->next;
                p->next=temp;
                printf("\nEnter the station number: ");
                scanf("%d",&temp->stationNumber);
                printf("Enter the station name: ");
                scanf("%s",temp->stationname);
                printf("Enter the station frequency: ");
                scanf("%f",&temp->frequency);
                printf("\n");
            }
        }
        return first;
    }
    if(ch=='C')
    {
        //when the user wants to insert at the last position
      struct Node *p=first;
      while(p->next!=NULL)
      {
          p=p->next;
      }
      struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
      p->next=temp;
      printf("\nEnter the station number: ");
      scanf("%d",&temp->stationNumber);
      printf("Enter the station name: ");
      scanf("%s",temp->stationname);
      printf("Enter the station frequency: ");
      scanf("%f",&temp->frequency);
      printf("\n");
      temp->next=NULL;
      return first;
    }
}
struct Node *delete_a_node(struct Node *first)
{
    //This is called when the user wants to perform deletion
    char ch;
    struct Node *p=first,*q=NULL;
    printf("\nA. Delete a station at the beginning");
    printf("\nB. Delete a station at a specified position");
    printf("\nC. Delete a station at the end\n");
    printf("\nEnter your choice: ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='A')
    {
        //if the user wants to delete the first node
        p=p->next;
        free(first);
        return p;
    }
    else if(ch=='B')
    {
        //if the user wants to delete at a specific position
        int pos;
        printf("\nEnter the position at which deletion is needed : ");
        scanf("%d",&pos);
        int i;
        for(i=0;i<pos-1;i++)
        {
            if(p->next==NULL)
                break;
            q=p;
            p=p->next;
        }
        if(p->next==NULL)
        {
            q->next=NULL;
            free(p);
        }
        else
        {
            q->next=p->next;
            free(p);

        }
        return first;
    }
    if(ch=='C')
    {
        //if the user wants to delete at the last position
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
        return first;
    }
}
void display(struct Node *temp)
{
    //This is called when the user wants to view the list of all functions
    while(temp!=NULL)
    {
        printf("\nStation %d\t\t%s\t\t%.1f",temp->stationNumber,temp->stationname,temp->frequency);
        temp=temp->next;
    }
}
int main()  //The main() function - program execution starts here
{
    struct Node *p=createnewnode(); //inputting initial station details
    int choice=0;
    while(choice!=4)
    {
        //user menu
        printf("\n1. Enter a new station");
        printf("\n2. Delete a station");
        printf("\n3. Display the stations");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
                 //If user wants to perform insertion
                 p=insert_new_node(p);
                 break;
          case 2:
                 //If user wants to perform deletion 
                 p=delete_a_node(p);
                 break;
          case 3:
                 //if user wnats to see all stations
                 display(p);
                 break;
          case 4:
                 //termination the programs
                 printf("\nExited");
                 break;
          default :
                   printf("\nInput Invalid");
        }
    }
    return 0;
}