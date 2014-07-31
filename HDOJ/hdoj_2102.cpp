/*
PROG:   A�ƻ�
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

//#define onlinejudge

const int maxn = 15;

char maze[2][maxn][maxn];
bool IsSolved, hash[2][maxn][maxn];
int  casenum, N, M, T, sx, sy, sz, tx, ty, tz;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, z, t;
}NODE;

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.x=sx, c.y=sy, c.t=0, c.z=sz;
    IsSolved=false, hash[sz][sx][sy]=true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.x==tx && c.y==ty && c.z==tz)
        {
            if (c.t <= T)
            {
                IsSolved = true;
                printf("YES\n");
            }
                
            return ;
        }/* Reach to the destination */
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (n.x<0 || n.y<0 || n.x>=N || n.y>=M
                || maze[c.z][n.x][n.y]=='*')
                continue;
            
            if (maze[c.z][n.x][n.y] == '#')
            {
                if (maze[c.z^1][n.x][n.y]=='*'
					|| maze[c.z^1][n.x][n.y]=='#')
                    continue;
                else
                    n.z = c.z^1, n.t = c.t + 1;
            }/* Space-Time transmission machine */
            else
                n.z = c.z, n.t = c.t + 1;
            
            if (hash[n.z][n.x][n.y])
                continue;
            
            hash[n.z][n.x][n.y] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");

    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2102.txt", "r", stdin);
    freopen("E:\\hdoj_2102_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        memset(maze, 0, sizeof(maze));
        memset(hash, false, sizeof(hash));
        
        scanf("%d %d %d", &N, &M, &T);
        for (int z=0; z<2; ++z)
        {
            for (int x=0; x<N; ++x)
            {
                for (int y=0; y<M; ++y)
                {
                    //hash[z][x][y] = false;
                    cin >> maze[z][x][y];
                    if (maze[z][x][y] == 'S')
                        sx=x, sy=y, sz=z, maze[z][x][y]='.';
                    if (maze[z][x][y] == 'P')
                        tx=x, ty=y, tz=z, maze[z][x][y]='.';
                }
            }
        }/* Two Blocks of Maze */
        
        /*
        for (int z=0; z<2; ++z)
        {
            for (int x=0; x<N; ++x)
            {
                for (int y=0; y<M; ++y)
                    cout << maze[z][x][y];
                cout << endl;
            }
            cout << endl;
        }
        */
        bfs();
    }/* End of While */
    
    return 0;
}
