#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool PredictTheWinner(int* nums, int numsSize) {
    int i, j;
    int **f1, **T;

    f1 = (int **)malloc(sizeof(int *) * numsSize);
    T = (int **)malloc(sizeof(int *) * numsSize);
    for(i=0; i<numsSize; ++i)
    {
        f1[i] = (int *)malloc(sizeof(int) * numsSize);
        T[i] = (int *)malloc(sizeof(int) * numsSize);
    }

    for(i=0; i<numsSize; ++i)
    {
        T[i][i] = nums[i];
        f1[i][i] = nums[i];
        for(j=i+1; j<numsSize; ++j)
        {
            T[i][j] = T[i][j-1] + nums[j];
        }
    }

    for(i=1; i < numsSize; ++i)
    {
        for(j=0; j+i < numsSize; ++j)
        {
            f1[j][j+i] = T[j][j+i] - (f1[j][j+i-1] < f1[j+1][j+i] ? f1[j][j+i-1] : f1[j+1][j+i]);
        }
    }

    return f1[0][numsSize-1] >= T[0][numsSize-1] - f1[0][numsSize -1];
}

int main()
{
    int a[4] = {1, 5, 233, 7};
    bool result = PredictTheWinner(a,4);
    printf("%d\n", result);
}
