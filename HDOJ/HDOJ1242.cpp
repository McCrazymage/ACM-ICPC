#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

char maze[210][210];
int  vis[210][210];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  nNum, mNum, i, j, sx, sy;

struct Node
{
    int x;
    int y;
    int step;
};

int IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum)
    {
        return 0;
    }
    
    return 1;
}/* IsInBound */

void BFS()
{
    int  k;
    int  front = -1;
    int  rear = -1;
    int  isSolve = 0;
    struct Node dir, cur;
    struct Node q[40010] = {0};
    
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    q[++rear] = cur;
    
    vis[sx][sy] = 1;
    while (front != rear)
    {
        cur = q[++front];
        if (maze[cur.x][cur.y] == 'r')
        {
            isSolve = 1;
            break;
        }
        
        /**
         * ��Ϊû�п������������WA�������Σ� 
         * guards�Ĵ��ڿ��ܻ��ƻ��������������Ϊ��
         * ����costTime�����·��.����costTime��ͬ�� 
         *
         * �Ȳ��ı䵱ǰ�����꣬�ɵ�guard�Ժ󣬽�x��Ϊ����
         * ·����.������ѹ������У��������Ա���ͬ�� 
         ***/
        if (maze[cur.x][cur.y] == 'x')
        {
            ++cur.step;
            vis[cur.x][cur.y] = 1;
            maze[cur.x][cur.y] = '.';
            q[++rear] = cur;
        }
        else
        {
            for (k=0; k<4; ++k)
            {
                dir.x = cur.x + dx[k];
                dir.y = cur.y + dy[k];
                dir.step = cur.step + 1;
                
                if (!vis[dir.x][dir.y] && maze[dir.x][dir.y]!='#' 
                    && IsInBound(dir.x, dir.y))
                {
                    vis[dir.x][dir.y] = 1;
                    q[++rear] = dir;
                }
            }/* End of For */
        }    
    }/* End of While */
    if (isSolve)
    {
        printf("%d\n", cur.step);
    }
    else
    {
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}/* BFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1242.txt", "r", stdin);
    freopen("E:\\hdoj1242(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &nNum, &mNum))
    {
        getchar();
        memset(maze, 0, sizeof(maze));
        memset(vis, 0, sizeof(vis));
        
        for (i=0; i<nNum; ++i)
        {
            scanf("%s", maze[i]);   
        }/* End of For */
        
        /*
         * ��ΪAngel��ֻ��һ��Friend 
         * �����ж��friends 
         */
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<mNum; ++j)
            {
                if (maze[i][j] == 'a')
                {   /* �ҳ�Angel��λ�ã���Angel��λ�ÿ�ʼ̽�� */ 
                    sx = i, sy = j;
                }
            }
        }/* End of For */

        BFS();
    }/* End of While */
    
    return 0;
}
