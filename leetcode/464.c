#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canWin(int used, int *TABLE, int maxChoosableInteger, int desiredTotal)
{
    if(TABLE[used] != -1)
        return TABLE[used];
    int i=maxChoosableInteger, b = 1 << (maxChoosableInteger-1);
    for(;i >= 1 ; --i, b >>= 1)
    {
        if((used & b) != 0)
            continue;
        if(i>=desiredTotal || !canWin(used | b, TABLE, maxChoosableInteger, desiredTotal -i))
        {
            TABLE[used] = 1;
            return true;
        }
    }
    TABLE[used] = 0;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(maxChoosableInteger >= desiredTotal)
        return true;
    if(desiredTotal >= ((1+maxChoosableInteger)*maxChoosableInteger)>>1)
        return false;
    int *TABLE = (int *)malloc(sizeof(int)*(1<<maxChoosableInteger));
    for(int i=0; i < (1<<maxChoosableInteger); i++)
        TABLE[i] = -1;
    return canWin(0, TABLE, maxChoosableInteger, desiredTotal);
}

int main()
{
    bool result = canIWin(4, 6);
    printf("%d\n", result);
    return 0;
}
