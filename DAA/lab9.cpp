#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int knap[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (wt[i - 1] <= w)
                knap[i][w] = max(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
            else
                knap[i][w] = knap[i - 1][w];
        }
    }
    
    return knap[n][W];
}
int main()
{
    int n;
    int W;
    cout<<"Enter No Of Items Data:";
    cin>>n;
    int val[n], wt[n];
    cout<<"\nEnter the profit and weights:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val[i]>>wt[i];
    }
    cout<<"\nEnter the weight of Knapsack:";
    cin>>W;
    cout<<knapsack(W, wt, val, n);
    return 0;
}