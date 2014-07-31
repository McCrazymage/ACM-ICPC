#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

char a, b;
int  i, front, rear;
int  sx, sy, tx, ty, x, y, newx, newy;
int  qx[70], qy[70], dis[10][10], vis[10][10];
int  dx[] = {2, 2, 1, -1, -2, -2, -1, 1}; /* ����(X, Y)���ƶ���8����λX���� */ 
int  dy[] = {1, -1, -2, -2, -1, 1, 2, 2}; /* ����(X, Y)���ƶ���8����λY���� */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj2243.txt", "r", stdin);
    freopen("E:\\poj2243(result).txt", "w", stdout);
#endif

    while (~scanf("%c%d %c%d", &a, &sy, &b, &ty))
    {
        getchar(); /* ����ϴ������Ļس��� */ 
        /***
        printf("#%c%d %c%d#\n", a, sy, b, ty);
        ***/
        sx = a - 'a'+1;
        tx = b - 'a'+1;
        /*****
        printf("%d %d\n%d %d\n#\n", sx, sy, tx, ty);
        *****/
        if (sx==tx && sy==ty)
        {
            printf("To get from %c%d to %c%d takes 0 knight moves.\n", a, sy, b, ty);
        }/* End of If */
        else
        {
            /* ��� vis��dis ���� */
            memset(vis, 0, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            
            /* ������ */ 
            front = rear = 0;
            qx[rear] = sx;
            qy[rear] = sy;
            ++rear;
            
            vis[sx][sy] = 1;  /* �������Ϊ�ѱ����� */ 
            //dis[sx][sy] = 0;  /* Ԥ��dis */ 
            while (front < rear)
            {
                /* ����������� */ 
                x = qx[front];
                y = qy[front];
                ++front;
                
                if (x==tx && y==ty)
                {   /* �����յ� */ 
                    break;
                }
                
                for (i=0; i<8; ++i)
                {
                    /* ���ʣ�x��y�����ƶ���Χ�ڵ�8����λ */ 
                    newx = x + dx[i];
                    newy = y + dy[i];
                    if (!vis[newx][newy] && newx>=1 && newy>=1
                        && newx<=8 && newy<=8)
                    {
                        vis[newx][newy] = 1;  /* ��ǰ��λ����Ϊ�ѱ����� */ 
                        dis[newx][newy] = dis[x][y]+1; /* ��¼��ǰ�ƶ�·�����ƶ����� */
                        
                        /* ��ǰ��λ��� */ 
                        qx[rear] = newx;
                        qy[rear] = newy;
                        ++rear;
                    }
                }
            }/* End of while */
            
            printf("To get from %c%d to %c%d takes %d knight moves.\n", a, sy, b, ty, dis[tx][ty]);
        }/* End of Else */
    }/* End of While */
    
    return 0;
}
