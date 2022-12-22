#include <stdio.h>
void main()
{
    int size, i, a[10], even=0, odd=0;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    for(i=0; i<size; i++)
    {
        printf("Enter element number %d : ", (i+1));
        scanf("%d", &a[i]);
    }
    for(i=0; i<size; i++)
    {
        if(a[i]%2==0)
        even = even + a[i];
        else
        odd = odd + a[i];
    }
    printf("\nThe Sum of Odd numbers in this array is : %d", odd);
    printf("\nThe Sum of Even numbers in this array is : %d", even);
}