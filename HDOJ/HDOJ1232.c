#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int nNum, mNum;
int xNum, yNum;

struct node
{
    int rank;   /* ��¼���ϵ��� */ 
    int parent; /* ��¼���ϵ����� */ 
}t[1010];

int FindSet(int k)
{   /* ���� k �������ļ��� */ 
    if (k != t[k].parent)
    {
        k = FindSet(t[k].parent);
    }/* End of If */
    
    return k;
}

void Union(int x, int y)
{
    /* Ѱ�� x��y �����ļ��� */ 
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return ;
    }
    
    /* ·��ѹ�� */ 
    if (t[x].rank > t[y].rank)
    {
        t[y].parent = x;
    }
    else
    {
        if (t[x].rank == t[y].rank)
        {
            ++t[y].rank;
        }
        t[x].parent = y;
    }/* End of Else */
}

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1232.txt", "r", stdin);
    freopen("E:\\hdoj1232(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &nNum, &mNum), nNum!=0)
    {
        for (i=1; i<=nNum; ++i)
        {   /* ���ü��� */ 
            t[i].rank = 0;
            t[i].parent = i;
        }/* End of For */
        
        for (i=0; i<mNum; ++i)
        {
            scanf("%d %d", &xNum, &yNum);
            Union(xNum, yNum);    /* �ϲ��������� */
        }
        
        ans = -1;
        for (i=1; i<=nNum; ++i)
        {   /* ͳ��һ������Ϊ����ĳ�����������ȥһ����answer */ 
            if (t[i].parent == i)
            {
                ++ans;
            }
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
