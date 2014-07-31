/*
PROG:   Waiting ten thousand years for Love
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 104;

char maze[maxn][maxn];
bool IsSolved, hash[maxn][maxn][2];
int  N, M, T, P, sx, sy, tx, ty, casenum=1;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, t, magic;
    bool operator < (const node &a) const
    {
        return a.t < t;
    }
}NODE;

void bfs()
{
    NODE    c, n;
    priority_queue <NODE> q;
    
    c.x=sx, c.y=sy, c.t=0, c.magic=P;
    hash[sx][sy][0] = true; /* 0 - walk , 1 - fly */
    
    q.push(c);
    while (!q.empty())
    {
        c = q.top();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.t<=T)
        {
            IsSolved = true;
            printf("Yes, Yifenfei will kill Lemon at %d sec.\n", c.t);
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M || maze[n.x][n.y]=='#')
                continue;
            
            if (maze[c.x][c.y] == '@')  // only can fly over
            {
                if (c.magic < 1)    continue;
                n.t=c.t+1, n.magic=c.magic-1;
                if (hash[n.x][n.y][1])  continue;
                
                hash[n.x][n.y][1] = true;
                q.push(n);
            }
            else if (maze[c.x][c.y] == '.')
            {
                if (maze[n.x][n.y] == '@')
                {
                    if (c.magic < 1)    continue;
                    
                    n.t=c.t+1, n.magic=c.magic-1;
                    if (hash[n.x][n.y][1])  continue;
                    
                    hash[n.x][n.y][1] = true;
                    q.push(n);
                }
                else if (maze[n.x][n.y] == '.')
                {
                    n.t=c.t+2, n.magic=c.magic;
                    if (hash[n.x][n.y][0])  continue;
                    hash[n.x][n.y][0] = true;
                    q.push(n);
                    
                    if (c.magic < 1)    continue;
                    n.t=c.t+1, n.magic=c.magic;
                    if (hash[n.x][n.y][1])  continue;
                    hash[n.x][n.y][1] = true;
                    q.push(n);
                }
            }
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("Poor Yifenfei, he has to wait another ten thousand years.\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2653.txt", "r", stdin);
    freopen("E:\\hdoj_2653_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d %d", &N, &M, &T, &P))
    {
        memset(hash, 0, sizeof(hash));
        
        for (int i=0; i<N; ++i)
        {
            getchar();
            for (int j=0; j<M; ++j)
            {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    sx=i, sy=j, maze[i][j]='.';
                if (maze[i][j] == 'L')
                    tx=i, ty=j, maze[i][j]='.';
            }
        }/* End of For */
        
        printf("Case %d:\n", casenum++);
        bfs();
    }/* End of While */
    
    return 0;
}
