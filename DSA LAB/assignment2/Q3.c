#include <stdio.h>

int main()
{
    int row = 1, col = 1;
    int matrix[10][10];
    int sparserow[100];
    int sparsecol[100];
    int sparseval[100];
    printf("Enter no. of row and columns separated by spaces:");
    scanf("%d %d", &col, &row);
    int idx = 0;
    printf("Enter element:\n");

    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                sparserow[idx] = i;
                sparsecol[idx] = j;
                sparseval[idx] = matrix[i][j];
                idx++;
            }
        }
    }

    for (int i = 0;i<idx;i++)
    {
        printf("sparsematrix[%d][%d] = %d\n",sparserow[i],sparsecol[i],sparseval[i]);
    }
    return 0;
}