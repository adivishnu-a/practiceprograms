#include <stdio.h>
#include <stdlib.h>

int t,k=1;
struct node
{
    float frequency;
    char name[20];
    int number;
    struct node *prev;
    struct node *next;
};
struct node *head,*p;
struct node *create()
{
    struct node *c,*q;
    int i=0;
    head=(struct node*)malloc(sizeof(struct node));
    c=head;
    for(i=0;i<t;i++)
    {
     if(i==0)
     {
      scanf("%d", &head->number);
      scanf("%s",head->name);
      scanf("%f", &head->frequency);
     }
     else
     {
        q=(struct node*)malloc(sizeof(struct node));
        scanf("%d", &q->number);
        scanf("%s",q->name);
        scanf("%f", &q->frequency);
        q->prev=c;
        c->next=q;
        c=q;
     }
    }
    c->next=head;
    head->prev=c;
    return(head);
}
void playing(int r)
{
    if(r==1)
    {
        if(k==1)
        {
          p=head;
          printf("Station %d %s  %.1f\n", p->number,p->name,p->frequency);
        }
        else
        {
            p=p->next;
            printf("Station %d %s  %.1f\n",p->number,p->name,p->frequency);
        }
    }
    else if(r==2)
    {
            p=p->prev;
            printf("Station %d %s  %.1f\n", p->number,p->name,p->frequency);
    }
    else if(r==3)
    {
        p=head;
        printf("Station %d %s  %.1f\n", p->number,p->name,p->frequency);
    }
}
int main()
{
    int ch;
    scanf("%d",&t);
    head=create();
    p=head;
    while(ch!=4)
    {
        scanf("%d",&ch);
        if(ch>4)
        {
            printf("Wrong Choice!!\n");
        }
        switch(ch)
        {
            case 1:
            playing(1);
            break;
            case 2:
            playing(2);
            break;
            case 3:
            playing(3);
            break;
            case 4:
            break;
        }
        k++;
    }
    return 0;
}