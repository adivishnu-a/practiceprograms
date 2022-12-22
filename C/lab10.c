#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Names{   //structure to store the names
    char data[20];  //string
}x[200];

int n=200;

int read()
{
    //function to read the names from the input txt file
    FILE *fp = fopen("C:\\Users\\Lenovo\\Downloads\\name.txt", "r");
    for(int i=0; i<(n); i++)
        fscanf(fp,"%s", x[i].data); //reading the names one-by-one
    fclose(fp);
}

int write()
{
    //function to write the sorted names into the output file
    FILE *fp = fopen("C:\\Users\\Lenovo\\Downloads\\output.txt", "w");
    if (fp == NULL)
    {
        printf("\tError");
        exit(1);
    }
    for(int i=0; i<(n); i++)
        fprintf(fp,"%s\n", x[i].data);  //writing the names one-by-one
    fclose(fp);
}

void bubble_sort(struct Names x[200],int n)
{
    //funtion to perform the bubble sort operation
    int i,j;
    char temp[20]; //temporary string to help in swapping
    for(i=0;i<n;i++)    // loop to access each structure element
    {
        for(j=0;j<n-i-1;j++)    // loop to compare structure elements
        {
            // compare two adjacent string elements
            if(strcasecmp(x[j].data, x[j+1].data) > 0)  
            {
                //if they are not in required order
                //then swap the elements
                strcpy(temp, x[j].data);
                strcpy(x[j].data, x[j+1].data);
                strcpy(x[j+1].data, temp);
            }
        }
    }
    write();    //writing the output to the output file
}

void insertion_sort(struct Names x[200],int n)
{
    //function to perform insertion sort operation
    int i,j;
    char pick[20];  //for storing the picked string
    for(i=1;i<n;i++)
    {
        strcpy(pick, x[i].data);
        j=i-1;
        //Moving names higher than picked name to one position ahead of their current position
        while(strcasecmp(pick, x[j].data) < 0 && j>=0)
        {
            strcpy(x[j+1].data, x[j].data);
            j=j-1;
        }
        strcpy(x[j+1].data, pick);
    }
    write();    //writing the output to the output file
}

void merge(struct Names x[200], int l, int m, int r)
{
    //function to merge two substructures
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    //create temp structures
    struct Names left[n1], right[n2];
  
    //Copy data to temp strcutures left[] and right[]
    for (i = 0; i < n1; i++)
        strcpy(left[i].data, x[l+i].data);
    for (j = 0; j < n2; j++)
        strcpy(right[j].data, x[m + 1 + j].data);
  
    // Merge the temp structures back into x[l..r]
    i = 0; // Initial index of left substructure
    j = 0; // Initial index of right substructure
    k = l; // Initial index of merged substructure
    while (i < n1 && j < n2) {
        if(strcasecmp(left[i].data, right[j].data) <= 0) 
        {
            strcpy(x[k].data, left[i].data);
            i++;
        }
        else 
        {
            strcpy(x[k].data, right[j].data);
            j++;
        }
        k++;
    }
  
    //Copy the remaining elements of left[]
    while (i < n1) {
        strcpy(x[k].data, left[i].data);
        i++;
        k++;
    }
  
    //Copy the remaining elements of right[]
    while (j < n2) {
        strcpy(x[k].data, right[j].data);
        j++;
        k++;
    }
}

void merge_sort(struct Names x[200], int l, int r)
{
    if (l < r) 
    {
        int m = (l + r) / 2;
  
        // Sorting the first and second parts
        merge_sort(x, l, m);
        merge_sort(x, m + 1, r);
  
        merge(x, l, m, r);
    }
    write();    //writing the output to the output file
}

int main()
{
    int ch;
    read(); //reading the input data
    printf("Please select any option Given Below for Sorting : \n");
    while(1)
    {
        printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Exit\n");
        printf("\nEnter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                bubble_sort(x,n);   //if the choice is bubble sort
                break;
            case 2:
                insertion_sort(x,n);    //if the choice is insertion sort
                break;
            case 3:
                merge_sort(x, 0, (n-1));    //if the choice is merge sort
                break;
            case 4:
                write();    //writing the output to the output file
                return 0;
            default:
                printf("\nWrong choice!\n");
        }
    }
    return 0;
}