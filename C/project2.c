#include<stdio.h>
#include<math.h>
//By Adi Vishnu Avula
 
int board[10],count;    //Global variables

//function to check if any queen is in the same line/diagonal
//Returns 1 if everything is free of conflicts
int place(int row,int col)   
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        if(board[i]==col)
            return 0;
        else
            if(abs(board[i]-col)==abs(i-row))
                return 0;
    }
    return 1;   //conflict-free
}

//function for displaying the solution
void output(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n",++count);
    for(i=1;i<=n;++i)
        printf("\t%d",i);
    for(i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j)
        {
            if(board[i]==j)
                printf("\tQ");  //When the square contains a queen
            else
                printf("\t-");  //When the square doesn't contain a queen
        }
    }
}

//function to check positioning of queen
void queen(int row,int n)
{
    int col;
    for(col=1;col<=n;++col)
    {
        if(place(row,col))  //if there are no conflicts
        {
            board[row]=col; //queen is positioned
            if(row==n) 
                output(n); //displaying the output
            else 
                queen(row+1,n); //try next position queen
        }
    }
}

int main()  //main() function
{
    int n;    //local variable
    printf("\nEnter the Number of Queens : ");
    scanf("%d",&n); //Reading the user input
    queen(1,n); //function call
    return 0;
}