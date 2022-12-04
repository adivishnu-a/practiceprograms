#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *);

int main()
{
    int n, data, i;
    printf("\n Enter the number of elements:");
    scanf("%d",&n);
    struct node *head, *newnode, *temp;
     
    head=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data of node 1:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data of node %d:",i+1);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        temp->next=newnode;
        temp=temp->next;
    }
    printf("\n The list is: \n");
    display(head);
}

void display(struct node *head)
{
    struct node *p;
    for(p=head;p!=NULL;p=p->next)
    {
        printf("\t%d",p->data);
    }

}