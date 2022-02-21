#include <stdio.h>
//Program to demonstrate Binar Search
//By Adi Vishnu Avula - AP21110010186
int i;  //decraring i as global variable as it is used in many loops
int BSearch (int a[], int n, int s) //user defined function
{
    //the values of a[], n and s are taken from main()
    int first = 0; //this is the starting position of the searching range
    int last = n - 1;   //this is the ending position of search range
    int middle = (first+last)/2; //this is the middle element in the search range
    /*during the execution of the program, we check the equality of the middle element 
      with the search element, and proceed further based on the result
    We are using a while loop (iterative method) to search in binary search manner
    the loop will be executed as soon as the search range is valid, 
    i.e., first position <= last position*/
    while (first <= last)
    {
        //Now we use else-if ladder to check relation between middle element and search term(s)
        if (a[middle] < s)  // If s greater than middle element, ignore left half
        first = middle + 1;
        else if (a[middle] == s)    // Checking if s is present at middle position
        {
            printf("\nItem %d is present at location %d\n", s, middle);
            break;
        }
        else    // If s is smaller than middle element, ignore right half
        last = middle - 1;
        middle = (first + last)/2;  //finding the new middle position
    }
    if (first > last)      /*if there is no valid search range, 
    i.e., beginning position>last position, displaying that the element is not found*/
    printf("\n Item %d is not present in the array\n", s);
}
int main()  //The main() function, program execution starts here
{
    int a[20],n,s, j;  /*declaring required local variables
    a[20] is the integer array, with 20 being the maximum number of array elements
    n is the number of elements the user wants to input (size of array)
    s is the desired search term, and j is used to control loop during sorting*/
    printf("\nEnter the size of the array : ");
    scanf("%d",&n); //inputting the size of array
    printf("\nEnter the array elements : ");
    for(i=0;i<n;i++)    //inputting array elements one by one
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter your item to Search : ");
    scanf("%d",&s); //inputting the search term
    //Implementing selection sort to arrange in ascending order
    for (i = 0; i < n; ++i) //outer loop controlled by i
    {
        for (j = i + 1; j < n; ++j) //inner loop controlled by j
        {
            if (a[i] > a[j])
            { 
                //swapping the elements
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    //Displaying the array elements in ascending order
    printf("\nThe Array after sorting in ascending order : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    BSearch(a, n, s);   //calling the BSearch() function
    //and passing the array(a), size of array(n) and search term(s) to the function
    return 0;
}