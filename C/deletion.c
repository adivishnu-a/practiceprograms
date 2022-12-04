#include <stdio.h>  //Header file
//Program to deminstrate deletion of an element from an array
//By Adi Vishnu Avula - AP21110010186
int delete(int a[], int n, int pos);   //user defined function
int main()  //main() function, program execution starts here
{
    /*declaring the local variables a[20] - array, i - to use in loops
      n - no. of elements, pos - location of element to be deleted*/
    int i,a[20],n,pos;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n); //inputting the number of array elements
    printf("\n Enter the array elements :\n");
    for(i=0;i<n;i++)    //inputting the array elements one by one
    {
        //the loop runs when i=0 to i=(n-1) to cover the subsequent array indices
       printf("Enter a[%d]:",i);
       scanf("%d",&a[i]);
    }
    printf("\n The array is :\n");
    for(i=0;i<n;i++)    //displaying the array before deletion
    {
        printf("%3d",a[i]);     //prints array elements with spaces in between
    }
    printf("\n Enter the position at which you want you delete the element:");
    scanf("%d",&pos);   //inputting the position of the element that needs to be deleted
    delete(a, n, pos); //calling the delete() function, array passed by reference
    return 0;   //program successfully executed
}
int delete(int a[], int n, int pos)
{
    //this function deletes the elements, and prints the new array
    int i; //to control loops
    if (pos >= n+1) //if the position is out of the array boundary
    {
        printf("Deletion not possible\n"); //then "Deletion not possible" is displayed
        return 0; //and exit the function
    }
    else    //if a valid position is given, then
    {
        for(i=pos-1;i<n-1;i++)
        {
            /*the for loop starts from (pos-1) because array index starts from 0
              so the index of deletion element is 1 less than given position*/
            a[i]=a[i+1];
            //each element is replaced with the value of the next adjacend element
        }
    }
    printf("\n The array after deletion is :\n");
    for(i=0; i<n-1 ;i++)    //now the array elements are displayed after deletion
    {   
        //the loop runs when i=0 to i=n-2 to display the desired result
        printf("\t%d",a[i]);
    }
}