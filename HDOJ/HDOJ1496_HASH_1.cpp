// Accept  31ms  544k 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/* �����̷ֻ�Ϊ2�����֣�ǰһ�����������100*100�ֿ��� */
#define MAX 30093

int s[10010]={0};
int a, b, c, d, ans, temp, p, i, j;
struct HashTable
{
    int key;
    int num;
}hash[MAX];

/* ����̽�鷨 */
int LinearDe(int k)
{
    int d = k%MAX;
    
    if (d < 0)
    {
        d += MAX;
    }
    
    /***
     *  ǰһ��������Ҫ���ڽ��hash��ͻ 
     *  ��һ��������Ҫ���ڲ��� ax1^2+bx2^2 �Ľ��
     *  
     *  ����֤����hash[i].num���ؼ���Ƶ�ʣ�Ϊ0ǰ������
     *  ��������һ��Ԫ��λ�� hash[i] λ�ã���������̽�鷨
     *  �Ĺ������������룿��
     *
     *  ͬʱ����������̽�鷨���hash��ͻʱ����һ����������Ӱ��
     *  ǰһ����������Ϊ�����Դ���һ��λ�� hash[i] ��ʹ��
     *  hash[i].num!=0, hash[i].key=k
     *  ���仰˵��ֻҪ hash[i] �м�¼�ؼ��֣���ô�ض�����hash[i].num!=0 
     **/
    while (hash[d].num && hash[d].key!=k)
    {
        d = (d+1)%MAX;
    }/* End of While */

    return d;
}/* LinearDe */

int main()
{
    for (i=1; i<=10000; ++i)
    {
        s[i] = i*i;
    }/* End of For */
    
    while (~scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        if ((a>0 && b>0 && c>0 && d>0)
            || (a<0 && b<0 && c<0 && d<0))
        {   /* ͬ�ű�Ȼ�޽� */ 
            printf("0\n");
            continue;
        }/* End of If */
        
        memset(hash, 0, sizeof(hash));
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                temp = a*s[i] + b*s[j];
                p = LinearDe(temp);
                hash[p].key = temp;    /* ��¼�ؼ��� */ 
                ++hash[p].num;         /* ��¼�ؼ��ֵ�Ƶ�� */ 
            }
        }/* End of For */
        
        ans = 0;
        for (i=1; i<=100; ++i)
        {
            for (j=1; j<=100; ++j)
            {
                /*
                  ��Ϊax1^2+bx2^2+cx3^2+dx4^2 = 0,
                  �������㣺
                  ax1^2+bx2^2 = -(cx3^2+dx4^2) 
                */
                temp = -(c*s[i] + d*s[j]);
                p = LinearDe(temp);
                ans += hash[p].num;
            }
        }/* End of For */ 
        
        printf("%d\n", ans<<4); /* x1 x2 x3 x4 ��Ӧ��ͬ�������Σ�����һ���� 2^4 �ֿ��� */ 
    }/* End of While */
    
    return 0;
}
