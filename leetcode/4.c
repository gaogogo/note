#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double leftmax, rightmin;
    int m, i, j, is, ie;
    int *A, *B;

    if(nums1Size < nums2Size)
    {
        m = nums1Size;
        A = nums1;
        B = nums2;
    }else
    {
        m = nums2Size;
        A = nums2;
        B = nums2;
    }

    for(is = 0, ie = m; is <= ie;)
    {
        i = (is + ie)/2;
        j = (nums1Size + nums2Size + 1)/2 - i;

        if(i > 0 && A[i-1] > B[j])
        {
            ie = ie - 1;
            continue;
        }

        if(i < m && A[i] < B[j-1])
        {
            is = is + 1;
            continue;
        }

        if(A[i-1] <= B[j] && A[i] >= B[j-1])
            break;
    }
    if(i==0)
        leftmax = B[j-1];
    else if(j==0)
        leftmax = A[j-1];
    else
        leftmax = A[i-1] > B[j-1] ? A[i-1] : B[j-1];

    if(i==m)
        rightmin = B[j];
    else if(j==nums1Size + nums2Size - m)
        rightmin = A[i];
    else
        rightmin = A[i] < B[j] ? A[i] : B[j];

    if((nums1Size + nums2Size) % 2)
        return leftmax;
    else
        return (leftmax + rightmin) / 2.0;
}

int main()
{
    int nums1[2] = {1,3};
    int nums2[1] = {2};

    double r = findMedianSortedArrays(nums1, 2, nums2, 1);

    return 0;
}
