#include<stdio.h>
//Program to deminstrate insertion of an element into an array
//By Adi Vishnu Avula - AP21110010186

int insert(int a[], int size, int pos, int value);   //user defined function
int main()	//main() function, program execution starts here
{
	/*declaring the local variables a[20] - array, i - to use in loops
      size - no. of elements, pos - location of element to be inserted
	  value - value of the new element*/
	int a[20], i, size, pos, value;
	printf("Enter no of elements in array : ");
	scanf("%d",&size);	 //inputting the number of array elements
	printf("Enter Elements of array : \n");
	for(i=0; i<size; i++)	//inputting the array elements one by one
	{
		 //the loop runs when i=0 to i=(n-1) to cover the subsequent array indices
		printf("Enter element a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("\nThe Array is : \n");	//displaying the array before insertion
	for(i=0; i<size; i++)
	{
		printf("%d\t",a[i]);	//prints array elements with tab spaces in between
	}
	printf("\nEnter the position where you want to insert the element : ");
	scanf("%d",&pos); //inputting the position of the insertion element
	printf("Enter the value into that position : ");
	scanf("%d",&value);	//inputting the value of insertion element
	insert(a, size, pos, value);	//array passes by reference
	printf("\nFinal array after inserting the value is : \n");
	for(i=0; i<=size; i++)	//printing the new array
	{	
		//the new array is printed from index 0 to size+1
		printf("%d\t",a[i]);
	}
	return 0;	//successfully executed
}
int insert(int a[], int size, int pos, int value) //this function performs the insertion
{
	
	int i; //for controlling loops
	for(i=size-1; i>=pos-1; i--)	//adjusting the elements using a for loop
	{
		//loop runs from i=size-1 (last element) to i=pos-1 (place of insertion)
		a[i+1]=a[i];
		//each element is assigned the value of the element that is preceeding it
		//so all elements will be moved to 1 location towards right side
	}
	a[pos-1] = value;	//now the new element is inserted at the required position
}