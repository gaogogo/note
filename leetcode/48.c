#include <stdio.h>

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int n = matrixRowSize/2;
    int j, k, t;

    for(k=0; k < n; k++)
    {
        for(j=0; j < matrixRowSize-1-2k; j++)
        {
            t = matrix[k][k+j];
            matrix[k][k+j] = matrix[matrixRowSize-1-k-j][k];
            matrix[matrixRowSize-1-k-j][k] = matrix[matrixRowSize-1-k][matrixRowSize-1-k-j];
            matrix[matrixRowSize-1-k][matrixRowSize-1-k-j] = matrix[k+j][matrixRowSize-1-k];
            matrix[k+j][matrixRowSize-1-k] = t;
        }
    }
}
