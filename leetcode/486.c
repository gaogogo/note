#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool PredictTheWinner(int* nums, int numsSize) {
    int i, j;
    int **f1, **f2, **T;

    f1 = (int **)malloc(sizeof(int *) * numsSize);
    f2 = (int **)malloc(sizeof(int *) * numsSize);
    T = (int **)malloc(sizeof(int *) * numsSize);
    for(i=0; i<numsSize; ++i)
    {
        f1[i] = (int *)malloc(sizeof(int) * numsSize);
        f2[i] = (int *)malloc(sizeof(int) * numsSize);
        T[i] = (int *)malloc(sizeof(int) * numsSize);
    }

    for(i=0; i<numsSize; ++i)
    {
        for(j=numsSize - 1; j>=i; --j)
        {
            f1[i][j] = 0;
            f2[i][j] = 0;
            if(i == j)
            {
                f1[i][j] = f2[i][j] = T[i][j] = nums[i];
            }
        }
    }

    for(i=0; i<numsSize; ++i)
    {
        for(j=i+1; j<numsSize; ++j)
        {
            T[i][j] = T[i][j-1] + nums[j];
        }
    }

    for(i=0; i<numsSize; ++i)
    {
        for(j=i+1; j<numsSize; ++j)
        {
            f1[i][j] = nums[i]+T[i+1][j]-f2[i+1][j] > nums[j] + T[i][j-1]-f2[i][j-1]
            ? nums[i]+T[i+1][j]-f2[i+1][j] : nums[j] + T[i][j-1]-f2[i][j-1];
            f2[i][j] = nums[i]+T[i+1][j]-f1[i+1][j] > nums[j] + T[i][j-1]-f1[i][j-1]
            ? nums[i]+T[i+1][j]-f1[i+1][j] : nums[j] + T[i][j-1]-f1[i][j-1];
        }
    }

    return f1[0][numsSize-1] > f2[0][numsSize-1];
}

int main()
{
    int a[4] = {1,5,2};
    bool result = PredictTheWinner(a,3);
    printf("%d\n", result);
}
