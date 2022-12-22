#include <stdio.h>
int evensum(int b[], int n);
int oddsum(int b[], int n);
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
    odd=oddsum(a, size);
    even=evensum(a, size);
    printf("\nThe Sum of Odd numbers in this array is : %d", odd);
    printf("\nThe Sum of Even numbers in this array is : %d", even);
}
int evensum(int b[], int n)
{
    int sum=0, i;
    for(i=0; i<n; i++)
    {
        if(b[i]%2==0)
        sum = sum + b[i];
    }
    return sum;
}
int oddsum(int b[], int n)
{
    int sum=0, i;
    for(i=0; i<n; i++)
    {
        if(b[i]%2!=0)
        sum = sum + b[i];
    }
    return sum;
}