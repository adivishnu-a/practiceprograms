#include<stdio.h>
int main()
{
    int n, a[10], i, min=0, max=0, min1=0, max1=0, temp;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter Element No. %d : ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("The Array elements are : ");
    for(i=0; i<n; i++)
    {
        printf("\t%d", a[i]);
    }
    for(i=0; i<n; i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            min1=i;
        }
        if(a[i]>max)
        {
            max=a[i];
            max1=i;
        }
    }
    printf("\nThe Smallest Element : %d", a[min1]);
    printf("\nThe Largest Element : %d", a[max1]);
    temp = a[min1];
    a[min1] = a[max1];
    a[max1] = temp;
    printf("\nAfter interchanging the smallest and largest elements : ");
    for(i=0; i<n; i++)
    printf("\t%d", a[i]);
    return 0;
}