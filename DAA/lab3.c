#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void display(struct node *head)
{
    struct node *p = head;
    while( p!= NULL)
    {
        printf("%d --> ",p->value);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int a[3],i;
    struct node *list,*p;
    printf("Enter 3 elements seperated by space (e.g. 1 2 3 (press enter) ");
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(i=0;i<3;i++)
    {
        if(i==0)
        {
            list = (struct node *)malloc(sizeof(struct node));
            p = list;
        }
        else
        {
            p->next = (struct node *)malloc(sizeof(struct node));
            p = p->next;
        }
        p->value=a[i];
    }
    p->next=NULL;
    printf("\nThe list is. ");
    display(list);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = 15;
    temp->next = list;
    list = temp;
    printf("\nThe new list is (15 added at the begining place). ");
    display(list);
    p = list->next;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = 20;
    temp->next = p->next;
    p->next = temp;
    printf("\nThe new list is (20 added in 3rd place). ");
    display(list);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = 25;
    temp->next = NULL;
    p = list;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    printf("\n\nThe new list is (25 added at the end). ");
    display(list);
    return 0;
}
