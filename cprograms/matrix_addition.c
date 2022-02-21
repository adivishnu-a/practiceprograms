#include <stdio.h>
int main()
{
    int a[2][2], b[2][2], c[2][2], i, j;
    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
        printf("Enter element b%d%d: ", i + 1, j + 1);
        scanf("%d", &b[i][j]);
        }
    }
    printf("\nMatrix A: \n");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            printf("%d   ", a[i][j]);
            if (j == 2 - 1)
            {
                printf("\n\n");
            }
        }
    }
    printf("\nMatrix B: \n");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            printf("%d   ", b[i][j]);
            if (j == 2 - 1)
            {
                printf("\n\n");
            }
        }
    }
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nSum of two matrices: \n");
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            printf("%d   ", c[i][j]);
            if (j == 2 - 1)
            {
                printf("\n\n");
            }
        }
    }
    return 0;
}