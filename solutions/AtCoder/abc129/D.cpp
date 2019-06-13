#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 2005
using namespace std;
int n,m;
int r[M][M], d[M][M], l[M][M], u[M][M];
char in[M][M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        MSET(r, 0);
        MSET(d, 0);
        MSET(l, 0);
        MSET(u, 0);
        REP(i,1,n) scanf("%s", in[i]+1);

        auto isb = [&](int x,int y) {
            if (x>n || x<1) return true;
            if (y>m || y<1) return true;
            return in[x][y] == '#';
        };

        for (int i=n; i>=1; i--) for (int j=m; j>=1; j--) if (in[i][j]=='.') {
            if (isb(i+1, j)) d[i][j] = i;
            else d[i][j] = d[i+1][j];

            if (isb(i,j+1)) r[i][j] = j;
            else r[i][j] = r[i][j+1];
        }

        REP(i,1,n) REP(j,1,m) if(in[i][j] == '.') {
            if (isb(i-1, j)) u[i][j] = i;
            else u[i][j] = u[i-1][j];

            if (isb(i,j-1)) l[i][j] = j;
            else l[i][j] = l[i][j-1];
        }

        int ans = 0;
        REP(i,1,n)REP(j,1,m) if(in[i][j]=='.')
            ans = max(ans, d[i][j]-u[i][j] + r[i][j]-l[i][j] + 1);
        printf("%d\n", ans);
    }
    return 0;
}
