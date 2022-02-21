#include <stdio.h>

int main()
{
    int i,a[20],n,pos,ni;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("\n Enter the array elements...\n");
    for(i=0;i<n;i++)
    {
       printf("Enter a[%d]:",i);
       scanf("%d",&a[i]);
    }
    printf("\n The array is....\n");
    for(i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n Enter the position at which you want you delete the element:");
    scanf("%d",&pos);
    if (pos >= n+1)
    printf("Deletion not possible.\n");
    else
    {
        for(i=pos-1;i<n-1;i++)
        {
           a[i]=a[i+1];
        }
    }
    printf("\n The array after deletion is...\n");
    for(i=0; i<n-1 ;i++)
    {
        printf("%3d",a[i]);
    }
    return 0;
}