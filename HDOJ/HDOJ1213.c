#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int xNum, yNum;
int tNum, nNum, mNum;
int rank[1010];     /* ���漯�ϵ��� */
int parent[1010];   /* ���漯�ϸ�Ԫ�ش����ļ��� */

int FindSet(int k)
{
    if (k != parent[k])
    {
        k = FindSet(parent[k]);
    }/* End of If */
    
    return k;
}

void Union(int x, int y)
{
    /* ����x��y�������ļ��� */ 
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return ;
    }
    
    /* ·��ѹ�� */ 
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            ++rank[y];
        }
        parent[x] = y;
    }/* End of Else */
}

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1213.txt", "r", stdin);
    freopen("E:\\hdoj1213(result).txt", "w", stdout);
#endif

    scanf("%d", &tNum);
    while (tNum--)
    {
        scanf("%d %d", &nNum, &mNum);
        
        for (i=1; i<=nNum; ++i)
        {   /* ���ü���Ԫ�� */ 
            rank[i] = 0;
            parent[i] = i;
        }/* End of For */
        
        for (i=0; i<mNum; ++i)
        {
            scanf("%d %d", &xNum, &yNum);
            Union(xNum, yNum); /* �ϲ��������� */ 
        }/* End of For */
        
        ans = 0;
        for (i=1; i<=nNum; ++i)
        {   /* ͳ�Ƽ��ϵĸ��������parentָ������˵����һ�������ļ��� */ 
            if (parent[i] == i)
            {
                ++ans;
            }
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
