#include <stdio.h>

double mypow(double x, int n)
{
    if(n == 0)
        return 1;
    if(n < 0)
    {
        n = -n;
        x = 1/x;
    }

    return n%2 ? x * mypow(x*x, n/2) : mypow(x*x, n/2);
}

int main()
{
    double result = mypow(2.0, -214);
    printf("%lf\n", result);
}
