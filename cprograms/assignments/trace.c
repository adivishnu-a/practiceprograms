#include<stdio.h>
#include<conio.h>
int main()
{
    int a[5][5],r,c,i,j,sum=0;
    printf("Enter a number of rows : ");
    scanf("%d",&r);
    printf("Enter a number of columns : ");
    scanf("%d",&c);
    if(r==c)
    {
        printf("\nEnter elements in matrix:-\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("Enter : ");
                scanf("%d", &a[i][j]);
            }
        }
        printf("\nThe Given Matrix is \n");
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++) 
            {
                printf("%d   ", a[i][j]);
                if (j == c - 1)
                printf("\n\n");
            }
        }
        for(i=0;i<r;i++) 
        sum=sum+a[i][i];
        printf("\nTrace of the matrix = %d\n",sum); 
    }
    else
    printf("It is not possible to find trace since it is not a square matrix");  
    return 0;
}