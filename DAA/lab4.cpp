#include<iostream>
using namespace std;
int vertArr[20][20];


void displayMatrix(int v)
 {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

void add_edge(int u, int v) 
{
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}

void remove_edge(int u, int v) 
{
   vertArr[u][v] = 0;
   vertArr[v][u] = 0;
}

int main()
{
    int v;
   cout<<"Enter the number of vertices: ";
   cin>>v;
   for(int i = 0;i < 20;i++)
   {
    for(int j = 0;j < 20;j++)
    {
        vertArr[i][j] = 0;
    }
   }
   add_edge(0, 1);
   add_edge(0, 2);
   add_edge(1, 2);
   add_edge(1, 3);
   add_edge(2, 4);
   add_edge(3, 4);
   remove_edge(3, 4);
   displayMatrix(v);
   return 0;
}