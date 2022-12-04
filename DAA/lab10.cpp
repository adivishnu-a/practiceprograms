#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        char ch;
        int freq;
        struct node *left;
        struct node *right;
}node;

node * heap[100];
int size=0;

void Insert(node * element)
{
        size++;
        heap[size] = element;
        int now = size;
        while(heap[now/2] -> freq > element -> freq)
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = element;
}
node * RemoveMinimum()
{
        node * mini,*last;
        int child,now;
        mini = heap[1];
        last = heap[size--];
        for(now = 1; now*2 <= size ;now = child)
        {
             child = now*2;
                 if(child != size && heap[child+1]->freq < heap[child] -> freq )
                {
                        child++;
                }
                if(last -> freq > heap[child] -> freq)
                {
                        heap[now] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[now] = last;
        return mini;
}
void Display(node *temp,char *code)
{
        if(temp->left==NULL && temp->right==NULL)
        {
                printf("char %c code %s\n",temp->ch,code);
                return;
        }
        int len = strlen(code);
        char leftcode[10],rightcode[10];
        strcpy(leftcode,code);
        strcpy(rightcode,code);
        leftcode[len] = '0';
        leftcode[len+1] = '\0';
        rightcode[len] = '1';
        rightcode[len+1] = '\0';
        Display(temp->left,leftcode);
        Display(temp->right,rightcode);
}
int main()
{

       heap[0] = (node *)malloc(sizeof(node));
        heap[0]->freq = 0;
        int n ;
       
        scanf("%d",&n);
        char ch;
        int freq,i;

        for(i=0;i<n;i++)
        {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;
                Insert(temp);
        }
        if(n==1)
        {
                printf("char %c code 0\n",ch);
                return 0;
        }
        for(i=0;i<n-1 ;i++)
        {
                node * left = RemoveMinimum();
                node * right = RemoveMinimum();
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                Insert(temp);
        }
        node *tree = RemoveMinimum();
        char code[10];
        code[0] = '\0';
        Display(tree,code);

}