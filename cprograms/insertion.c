#include<stdio.h>
int main(){
	int a[50], pos, i, size, value;
	printf("Enter no of elements in array : ");
	scanf("%d",&size);
	printf("Enter Elements of array : \n");
	for(i=0; i<size; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\nThe Array is : ");
	for(i=0; i<size; i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n\nEnter the position where you want to insert the element : ");
	scanf("%d",&pos);
	printf("Enter the value into that poition : ");
	scanf("%d",&value);
	for(i=size-1; i>=pos-1; i--)
	{
		a[i+1]=a[i];
	}
	a[pos-1] = value;
	printf("\nFinal array after inserting the value is : ");
	for(i=0; i<=size; i++)
	{
		printf("\t%d",a[i]);
	}
	return 0;
}