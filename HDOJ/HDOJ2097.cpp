#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int testNum;
int decSum, hexSum, duodecSum;

int GetSum(int testnum, int scale)
{
    int sum = 0;
    
    while (testnum)
    {
        sum += testnum%scale;
        testnum /= scale;
    }/* End of while */
    
    return sum;
}

int main()
{
    while (1==scanf("%d", &testNum), testNum!=0)
    {
        decSum = GetSum(testNum, 10);     /* ����ʮ�������ֵĺ� */ 
        duodecSum = GetSum(testNum, 12);  /* ����ʮ���������ֵĺ� */ 
        hexSum = GetSum(testNum, 16);     /* ����ʮ���������ֵĺ� */
        
        if (decSum==duodecSum && decSum==hexSum)
        {
            printf("%d is a Sky Number.\n", testNum);
        }
        else
        {
            printf("%d is not a Sky Number.\n", testNum);
        }
    }/* End of while */
    
    return 0;
}
