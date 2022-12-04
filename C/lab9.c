#include <stdio.h>
#include <stdlib.h>
//By Adi Vishnu Avula - AP21110010186

#define N 9

//Global variable declaration
int q[20],top=-1,front=-1,rear=-1,visited[20],stack[20];

//NxN matrix to store N vertices of the graph initially
int a[N][N]=
{
    //0,1,2,3,4,5,6,7,8  
    {0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0},
    {0,0,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,0,0,0},
    {0,0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,1,1,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0}
};  //Matrix initialized according to the given graph

void add_now(int item) 
{
    //User defined function used to add an element to the queue
    if(rear==19)    //If the position is at last index i.e., 19
        printf("QUEUE FULL");   //Displaying that the queue is full
    else
    {
        if(rear==-1)
        {
            q[++rear]=item;    //Adding the item towards the backside
            front++;    //incrementing the front value
        }
        else
            q[++rear]=item;     //Adding the item towards the backside
    }
}

int delete_now()
{
    //User defined function used to delete an element from the queue
    int k;
    if((front>rear)||(front==-1))
        return(0);
    else
    {
        k=q[front++];
        return(k);
    }
}

void push(int item) //User defined push() function  for stack
{
    if(top==19)
        printf("Stack overflow");
    else
        stack[++top]=item;
}

int pop()   //User defined pop() function for stack
{
    int k;
    if(top==-1)
        return(0);
    else
    {
        k=stack[top--];
        return(k);
    }
}

void DFS_traversal(int s,int n)
{
    //User defined function to perform DFS traversal
    int i,k;    //Local variables
    push(s);    
    visited[s]=1;   //Mark the current node as visited
    k=pop();        //Pop a vertex from queue and print it
    printf(" %d,",k);
    for(i=0;i<=n;i++)
    {
        if((a[k][i]!=0) && (visited[i]==0))
        {
            DFS_traversal(i,n); //Recursive call
        }
    }
}
void BFS_traversal(int s, int n)
{
    //User defined function to perform BFS traversal
    int p,i;
    add_now(s);
    visited[s]=1;   //Mark the current node as visited
    p=delete_now(); //Dequeue a vertex from queue and print it
    if(p==0)
        printf(" %d,",p);
    
    //Get all adjacent vertices of the dequeued vertexes. 
    //If a adjacent has not been visited, then mark it visited and enqueue it
    do
    {
        for(i=1;i<=n;i++)
            if((a[p][i]!=0)&&(visited[i]==0))
            {
                add_now(i);     //Enqueuing it
                visited[i]=1;   //setting that node as visited
            }
        p=delete_now();
        if(p!=0)
            printf(" %d,",p);
    }
    while(p!=0);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
            BFS_traversal(i,n); //Recursive call
}

int main()
{
    int chs, n=9, i;
    while(1)
    {
        for(i=1;i<=n;i++)
            visited[i]=0; // Mark all the vertices as not visited
        scanf("%d",&chs);   //Take the user's choice input
        switch(chs)
        {
            case 1: //If user selects 1
                printf("DFS Traversal:");
                DFS_traversal(0, 8);    //perform DFS traversal
                break;

            case 2: //If user selects 2
                printf("\n\nBFS Traversal:");
                BFS_traversal(0, 8);    //Perform BFS traversal
                break;

            case 3: //If user selects 3
                exit(0);    //Terminate the program

            default:    //If choice is out of range
                printf("\nWrong choice!! Please enter correct choice");
        }
    }
    return 0;
}
