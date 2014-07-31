#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define INF 0x3f3f3f3f

int nNum, ans;
int mat[110][110];

int prim()
{
    int result = 0;
    int pos, min, i, j;
    int visit[110] = {0};
    int lowcost[110] = {0}; /* ���� (pos, i)�� ������Ȩֵ */ 
    
    /* ������� */ 
    pos = 0, visit[0] = 1;
    for (i=1; i<nNum; ++i)
    {
        lowcost[i] = mat[pos][i];
    }/* End of For */
     
    /* �� N-1 ��������в��� */ 
    for (i=1; i<nNum; ++i)
    {
        min = INF;
        for (j=0; j<nNum; ++j)
        {
            if (visit[j]==0 && min>lowcost[j])
            {
                pos = j; /* ��¼�����������Ȩֵ���ٵĶ���λ�� */ 
                min = lowcost[j]; /* ��¼��ǰ���ٱ�Ȩֵ */ 
            }
        }/* End of for */
        
        result += min;  /* ÿ������Ȩֵ��� */
        visit[pos] = 1; /* pos��������Ϊ�ѱ����� */
        
        /* ���� lowcost */ 
        for (j=0; j<nNum; ++j)
        {
            if (visit[j]==0 && lowcost[j]>mat[pos][j])
            {
                lowcost[j] = mat[pos][j];
            }
        }/* End of for */
    }/* End of For */
    
    return result;
}

int main()
{
    int i, j;
    
    while (1 == scanf("%d", &nNum))
    {
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<nNum; ++j)
            {
                scanf("%d", &mat[i][j]);
            }
        }/* End of For */
        
        ans = prim(); /* ���� prim �㷨�������������� */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
