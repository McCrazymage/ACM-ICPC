#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int nNum, casenum=1;
int vis[30];   /* ���÷������� */ 
int seq[30];   /* �������� */ 
int IsPrime[50] = {1, 1, 0};  /* ����40���ڵ����� */ 

void DFS(int cur)
{
    int i;
    if (cur==nNum+1 && (!IsPrime[1+seq[cur-1]]))
    {   /* �˳���������ǰseq����һ������������� */
        for (i=1; i<=nNum; ++i)
        {
            printf(i==1? "%d":" %d", seq[i]);
        }
        printf("\n");
        
        return ;
    }/* End of If */

    for (i=2; i<=nNum; ++i)
    {   /* ��̽�Է���һ�����֣����Ƿ��������� */ 
        if (vis[i]==0 && (!IsPrime[seq[cur-1]+i]))
        {   /* ��ǰ�������֮�������� */
            vis[i] = 1;     /* ����Ϊ�ѱ����� */ 
            seq[cur] = i;   /* ���浱ǰֵ */ 
            DFS(cur+1);     /* ����������һ��λ�� */
            vis[i] = 0;     /* ��������Ϊδ������ */ 
        }
    }
}/* DFS */

int main()
{
    int i, j;
    for (i=2; i<=(int)sqrt(40); ++i)
    {
        if (!IsPrime[i])
        {
            for (j=i*i; j<=40; j+=i)
            {
                IsPrime[j] = 1;
            }
        }
    }/* End of For */

    while (1 == scanf("%d", &nNum))
    {
        if ((nNum&1) == 0)
        {   /* ֻ�е� N Ϊż��ʱ�����γ������� */ 
            memset(vis, 0, sizeof(vis));
            printf("Case %d:\n", casenum++);
    
            seq[1] = 1;
            DFS(2); /* ��λ�� 2 ��ʼ��������Ϊ���ʼ���Ǵ� 1 ��ʼ */
            
            printf("\n");
        }     
    }/* End of While */

    return 0;
}
