#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int nNum, mNum;
int rank[110] = {0};    /* ���ϵ��� */ 
int parent[110] = {0};  /* ���ϵĴ�����ϵ */ 
struct node
{
    int u;  /* ��� */ 
    int v;  /* β�� */ 
    int w;  /* Ȩֵ */ 
}edge[110];

/* Sorting for the edge(u,v) in ascending order*/ 
int compare(const void *a, const void *b)
{
    return (*(node *)a).w - (*(node *)b).w;
}/* Compare */

int FindSet(int k)
{
    while (k != parent[k])
    {
        k = parent[k];
    }/* End of While */
    
    return k;
}/* FindSet */

void Union(int x, int y)
{
    /* ����Ԫ��x��y�����ļ��ϱ�� */ 
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
    }
}/* Union */

int Kruskal()
{
    int cnt = 0;    /* ͳ���Ѿ����ɵı��� */ 
    int result = 0; /* ��¼����kruskal�㷨������������������Ȩֵ */ 
    int j, sn1, sn2;
    
    for (j=1; j<=mNum; ++j)
    {
        /* ȡһ����(u,v), sn1, sn2�õ� u, v �������������ļ��ϱ�� */ 
        sn1 = FindSet(edge[j].u);
        sn2 = FindSet(edge[j].v);
        if (sn1 != sn2)
        {   /* �������㲻��ͬһ�����ϣ�˵�������γɻ�·��
             * ��ߣ�u��v����������������һ����
             **/
             ++cnt;  /* ���ɵı�������һ */ 
             result += edge[j].w;  /* ͳ�����ٵ�Ȩֵ */ 
             Union(sn1, sn2);      /* �� u �� v ��������ϲ� */ 
        }
    }/* End of While */
    
    if (cnt == mNum-1)
    {   /* ���ɱ���Ϊ M-1 ʱ˵������������������� */ 
        return result;
    }
    else
    {
        return 0;
    }
}/* Kruskal */

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1863.txt", "r", stdin);
    freopen("E:\\hdoj1863(result).txt", "w", stdout);
#endif

    while (2==scanf("%d %d", &nNum, &mNum), nNum!=0)
    {
        memset(edge, 0, sizeof(edge));
        for (i=1; i<=nNum; ++i)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }/* End of For */
        
        /* ��ʼ�����鼯�� */
        for (i=1; i<=mNum; ++i)
        {   /* ע��i��1��ʼ */ 
            rank[i] = 0;
            parent[i] = i;
        }/* End of For */
        
        /* ��edge�ı߼������������� */ 
        qsort(edge, mNum, sizeof(edge[0]), compare);
        
        ans = Kruskal(); // ����Kruskal�㷨��������������
        if (ans)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("?\n");
        }
    }/* End of While */
    
    return 0;
}
