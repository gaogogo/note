#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pathlong(int **src, int **visit, int row, int col, int ri, int ci)
{
    int max = -1;
    int temp;
    visit[ri][ci] = 1;
    if(ri-1 >= 0 && src[ri-1][ci] > src[ri][ci])
    {
        temp = visit[ri-1][ci] ? visit[ri-1][ci] : pathlong(src, visit, row, col, ri-1, ci);
        max = max > temp ? max : temp;
    }

    if(ri+1 <= row-1 && src[ri+1][ci] > src[ri][ci])
    {
        temp = visit[ri+1][ci] ? visit[ri+1][ci] : pathlong(src, visit, row, col, ri+1, ci);
        max = max > temp ? max : temp;
    }

    if(ci-1 >= 0 && src[ri][ci-1] > src[ri][ci])
    {
        temp = visit[ri][ci-1] ? visit[ri][ci-1] : pathlong(src, visit, row, col, ri, ci-1);
        max = max > temp ? max : temp;
    }

    if(ci+1 <= col-1 && src[ri][ci+1] > src[ri][ci])
    {
        temp = visit[ri][ci+1] ? visit[ri][ci+1] : pathlong(src, visit, row, col, ri, ci+1);
        max = max > temp ? max : temp;
    }

    if(max != -1)
        visit[ri][ci] = max + 1;

    return visit[ri][ci];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize==0 && matrixColSize == 0)
        return 0;
    int i, j;
    int result = 1;
    int temp;

    int **visit;
    visit = (int **)malloc(sizeof(int *) * matrixRowSize);
    for(i=0; i< matrixRowSize; i++)
    {
        visit[i] = (int *)malloc(sizeof(int) * matrixColSize);
    }
    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            visit[i][j] = 0;
        }
    }

    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            if(visit[i][j] != 0)
                continue;
            temp = pathlong(matrix, visit, matrixRowSize,  matrixColSize, i, j);
            result = result > temp ? result : temp;
        }
    }
    return result;
}

int main()
{
    int **a;
    a = (int **)malloc(sizeof(int *) * 4);
    a[0] = (int *)malloc(sizeof(int) * 4);
    a[1] = (int *)malloc(sizeof(int) * 4);
    a[2] = (int *)malloc(sizeof(int) * 4);
    a[3] = (int *)malloc(sizeof(int) * 4);
    a[0][0] = 0;
    a[0][1] = 9;
    a[0][2] = 7;
    a[0][3] = 0;
    a[1][0] = 7;
    a[1][1] = 4;
    a[1][2] = 1;
    a[1][3] = 9;
    a[2][0] = 2;
    a[2][1] = 6;
    a[2][2] = 1;
    a[2][3] = 3;
    a[3][0] = 8;
    a[3][1] = 0;
    a[3][2] = 9;
    a[3][3] = 9;
    int result = longestIncreasingPath(a, 4, 4);
    printf("%d\n", result);
    return 0;
}
