#include <stdio.h> //Header files
//Program to demonstrate Linear Search - Adi Vishnu A - AP21110010186
int LSearch (int a[], int n, int s) //User-defined function
{
    //array, number of elements and search element are passed from the main function
    //declaring i and found as local variables
    int i,found=-1;
    //declaring i for controlling loops, and found for checking if term exists or not
    for(i=0;i<n;i++)//for loop to check each element one by one
    {
        if(a[i]==s) //checking if the search term is equal to array element at index i
        {
            found=(i+1);    //if element is found, assign value of i+1 to found
            break;      //and the control comes out of the loop
        }
    }
    if(found>-1)//if found is >-1 (that means search term is found)
    {
        //Printing the position at where the search term is found
        printf("\nItem %d found at location %d.",s,found);
    }
    else
    {
        //if found is still = -1, then we'll print that element is not found
        printf("\nItem %d is not present in the array", s);
    }
}
int main()  //The main function, execution starts from here
{
    int a[20], i, n,s; //initializing local variables in main
    // a[] is the array, i is for controlling loops
    // n is the number of elements the user wants to input
    //s is the search term that need to be checked 
    printf("\nEnter the size of the array : ");
    scanf("%d",&n); //Inputting the number of array elements
    printf("\nEnter the array elements : ");
    for(i=0;i<n;i++)    //inputting the array elements one by one
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter your term to search : ");
    scanf("%d",&s); //inputting the search element
    LSearch(a, n, s); //calling the LSearch function
    //and passing the array(a), number of elements(n) and search term(s)
    return 0;
}