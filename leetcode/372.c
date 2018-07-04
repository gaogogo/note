#include <stdio.h>

#define M 1337

int pow1(int base, int p)
{
    int result = 1;
    int i = 0;
    for (; i < p; i++)
        result = (result * base) % M;
    return result;
}

int superpow(int a, int* b, int bsize)
{
    int base = a % M;
    int result = 1;
    int i = bsize;
    while (i--) {
        result = (result * pow1(base, b[i]))%M;
        base = pow1(base, 10);
    }

    return result;
}
