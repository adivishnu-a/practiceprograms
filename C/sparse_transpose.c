#include <stdio.h>  //Header File
/* Program to print transpose of a sparse matrix
   By Adi Vishnu Avula - AP21110010186   */
void transpose(int[][3], int[][3]); //prototype of user defined function

int main()  //The main() function - program execution starts here
{
    int i, sp[15][3], tr[15][3], r, c, n;   //variable declaration
    /*i - to control loops; sp[][] - to store the sparse matrix in triplet form
      r - to store number of rows; c - to store number of columns; 
      n - to store number of non zero elements in sparse matrix; 
      tr - to store the transpose of sparse matrix;  */
    printf("How many matrix row, column and no_of_entries: ");
    //inputting rows(r), columns(c) and number of non zero values(n)
    scanf("%d%d%d", &r, &c, &n);
    sp[0][0]=r; //placing value of r in the top row of sp[][0]
    sp[0][1]=c; //placing value of c in the top row of sp[][1]
    sp[0][2]=n; //placing value of n in the top row of sp[][2]
    for(i=1; i<=n; i++)
    {
    printf("Enter the corresponding matrix row, column and value: ");
    //inputting one-by-one  non zero element in triplet form
    scanf("%d%d%d",&sp[i][0],&sp[i][1],&sp[i][2]);
    }
    //Printing the sparse matrix (triplet form) before transposing
    printf("\n\nInitial Matrix information in triplet format:");
    printf("\n%d\t%d\t%d", sp[0][0], sp[0][1], sp[0][2]);
    printf("\n----------------------");
    for(i=1; i<=n; i++)
    {
        printf("\n%d\t%d\t%d", sp[i][0], sp[i][1], sp[i][2]);
    }
    transpose(sp, tr);  //function call - using call by reference
    //Printing the sparse matrix (triplet form) after transposing
    printf("\n\nTranspose Matrix in triplet format:");
    printf("\n%d\t%d\t%d", tr[0][0], tr[0][1], tr[0][2]);
    printf("\n----------------------");
    for(i=1; i<=n; i++)
    {
        printf("\n%d\t%d\t%d", tr[i][0], tr[i][1], tr[i][2]);
    }
    return 0;   //successfully executed the program
}
void transpose(int sp[][3], int tr[][3])    //Function used to perform transpose
{
    //sp[][] and tr[][] are read from main()
    int i, j, k=1;  //variable declaration
    // i, j - to control loops; k - to store the row of tr[][]
    //Assigning values to the top row in tr[][] - triplet representation
    tr[0][0]=sp[0][1];  //No. of columns in sp[][] = No. of rows in tr[][]
    tr[0][1]=sp[0][0];  //No. of rows in sp[][] = No. of columns in tr[][]
    tr[0][2]=sp[0][2];  //No. of non zero elements is same
    for(i=0; i<sp[0][1]; i++)   //Outer loop
    {
        for(j=1; j<=sp[0][2]; j++)  //Inner loop
        {
            /* if a column number of current element==i then,
               insert that triplet in tr[][] by swapping row and column value */
            if(i==sp[j][1])
            {
                tr[k][0]=i;
                tr[k][1]=sp[j][0];
                tr[k][2]=sp[j][2];
                k++;
            }
        }
    }
}