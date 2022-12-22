#include<stdio.h>

#define INFINITE 99999

void dijkstra(int G[5][5], int n, int begin);

int main()
{
    int u=0, n=5;    //local variables
    int G[5][5]=
    {
        //multi dimensional array to store the graph distances
        {0,3,1,0,0},
        {3,0,7,5,1},
        {1,7,0,2,0},
        {0,5,1,0,7},
        {0,1,0,7,0}
    };
    dijkstra(G,n,u);
    return 0;
}

void dijkstra(int G[5][5], int n, int begin)
{
    int k, minimum, next, i, j, total[5][5], distance[5], visited[5];
    /*  total[][] - total[][] - Multi-D array to store the totals
        distance[] - array to store the distances between nodes
        visited[] - array to remember nodes that are already visited  */
    for(i=0;i<n;i++)
    {
        //Going through all edges to calculate the totals
        for(j=0;j<n;j++)
        {
            //If two nodes are not connected directly, then setting total as 99999
            if(G[i][j]==0)
                total[i][j]=INFINITE;
            //If two nodes are connected directly, then total = distance between those nodes
            else
                total[i][j]=G[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        distance[i]=total[begin][i]; //storing the distances from staring node
        visited[i]=0;       //setting all nodes from visited to 0
    }
    distance[begin]=0;      //distance of starting node is zero
    visited[begin]=1;       //setting the source node visited to 1 
    k=1;                    //k of one node is set to 1
    while(k < n)
    {
        //To find out the node with least distance
        minimum=INFINITE;   
        for(i=0;i<n;i++)
        {
            if(distance[i]<minimum && !visited[i])
            {
                minimum=distance[i];    //obtaining the value of minimum
                next=i;
            }
        }
        visited[next]=1;     //setting the node visited to 1
        for(i=0;i<n;i++)
        {
            //setting the distances of all other nodes
            if(!visited[i])
            {
                if(minimum + total[next][i] < distance[i])
                {
                    distance[i]=minimum + total[next][i];
                }
            }
        }
        k++;
    }
    printf("\nDistance from A to B is %d",distance[1]);
    printf("\nDistance from A to C is %d",distance[2]);
    printf("\nDistance from A to D is %d",distance[3]);
    printf("\nDistance from A to E is %d",distance[4]);
}