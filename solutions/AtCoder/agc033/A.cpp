#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
using namespace std;
typedef tuple<int,int,int> T;
int n,m,dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
char in[M][M];
bool vis[M][M];
queue<T> q;
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        REP(i,1,n) scanf("%s", in[i]+1);
        REP(i,1,n) REP(j,1,m) if(in[i][j]=='#') {
            q.push(make_tuple(i,j,0));
            vis[i][j] = true;
        }

        int ans = 0;
        int x,y,z;
        while (!q.empty()) {
            tie(x,y,z) = q.front();
            q.pop();
            ans = max(ans, z);

            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx>=1 && nx<=n && ny>=1 && ny<=m && !vis[nx][ny]) {
                    q.push(make_tuple(nx, ny, z+1));
                    vis[nx][ny] = true;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

