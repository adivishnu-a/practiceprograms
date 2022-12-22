#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if((rear==NULL)&&(front==NULL))
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void dequeue()
{
    struct node* temp;
    temp = front;
    if((front==NULL)&&(rear==NULL))
    {
        printf("\nQueue is Empty");
    }
    else if(front == rear)
    {
        front = rear = NULL;
        printf("\n%d is deleted", temp->data);
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        printf("\n%d is deleted", temp->data);
        free(temp);
    }
}

void display()
{
    struct node* temp;
    temp = front;
    if((front==NULL)&&(rear==NULL))
    {
        printf("\nQueue is Empty");
    }
    else
    {
        do
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }while(temp != front);
    }
}

int main()
{
    int choice, n, i, data; 
    do
    {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the number of values to insert : ");
                scanf("%d", &n);
                printf("\nEnter your data : ");
                i = 1;
                while(i<=n)
                {
                    scanf("%d", &data);
                    enqueue(data);
                    i++;
                }
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                exit(0);
            default:
                printf("\nIncorrect choice");

        }
    }while(choice != 4);
    return  0;
}