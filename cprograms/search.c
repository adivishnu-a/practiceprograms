#include <stdio.h>
int main()
{
    int a[10], i, ns, n, found=0;
    printf("Enter the No of elements : ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for(i=0; i<n; i++)
    {
        printf("Enter Element No.%d :", (i+1));
        scanf("%d", &a[i]);
    }
    printf("Enter the search element : ");
    scanf("%d", &ns);
    for(i=0; i<n; i++)
    {
        if(ns==a[i])
        {
            found=1;
            break;
        }
    }
    if(found==1)
    printf("Search Element %d found at array index %d", ns, i);
    else
    printf("Search Element NOT found");
}