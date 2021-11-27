#include<stdio.h>
int main()
{
    int n, i, j, a[10], temp;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter Element No. %d : ", (i+1));
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The elements in Ascending Order are : \n");
    for(i=0; i<n; i++)
    printf("%d\t", a[i]);
    return 0;
}