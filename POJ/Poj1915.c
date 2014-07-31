#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int i, j, x, y, nNum, casenum;
int tx, ty, sx, sy, front, rear, newx, newy;
int qx[90010], qy[90010]; /* ����������� */
int vis[310][310];        /* ���÷������� */ 
int dis[310][310];        /* ��¼�ƶ����� */ 
int dx[] = {2, 2, 1, -1, -2, -2, -1, 1}; /* ����(X, Y)���ƶ���8����λX���� */ 
int dy[] = {1, -1, -2, -2, -1, 1, 2, 2}; /* ����(X, Y)���ƶ���8����λY���� */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj1915.txt", "r", stdin);
    freopen("E:\\poj1915(result).txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &nNum);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &tx, &ty);
        
        /* vis, dis ������� */ 
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        
        /* ��ʼ����� */ 
        front = rear = 0;
        qx[rear] = sx;
        qy[rear] = sy;
        ++rear;
        
        vis[sx][sy] = 1; /* �������Ϊ�ѱ����� */ 
        while (front < rear)
        {
            /* ���ӣ���ö������� */ 
            x = qx[front];
            y = qy[front];
            ++front;
            
            if (x==tx && y==ty)
            {   /* �ߵ����ڣ��˳�ѭ�� */ 
                break;
            }
            
            for (i=0; i<8; ++i)
            {
                /* (X, y)�ƶ���Χ�ڵ�8�ݷ�λ */ 
                newx = x + dx[i];
                newy = y + dy[i];
                if (!vis[newx][newy] && newx>=0 && newy>=0
                    && newx<nNum && newy<nNum)
                {   /* ���е��ƶ���λ */
                    vis[newx][newy] = 1;           /* ��ǰλ������Ϊ�ѱ����ʹ� */ 
                    dis[newx][newy] = dis[x][y]+1; /* ��¼��ǰ�ƶ�·���ܵ��ƶ����� */
                    
                    /* ��ǰ��������� */ 
                    qx[rear] = newx;
                    qy[rear] = newy;
                    ++rear;
                }
            }
        }/* End of while */
        
        printf("%d\n", dis[tx][ty]);
    }/* End of While */
    
    return 0;
}
