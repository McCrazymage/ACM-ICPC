/*
PROG:   ������ϵ��֮(3)���� LELE��RPG����
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, i;
__int64 F[55]={0,3,6,6};

int main()
{
    for (i=4; i<=50; ++i)
        F[i] = (F[i-2]<<1) + F[i-1];

    while (~scanf("%d", &N))
    {
        printf("%I64d\n", F[N]);
    }
    
    return 0;
}
