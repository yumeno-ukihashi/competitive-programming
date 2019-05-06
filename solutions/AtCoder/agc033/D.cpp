#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 187
using namespace std;
int n,m;
int cnt[M][M];
int dp1[2][M][M][M]; //comp, x1, x2, y1 => y2
int dp2[2][M][M][M]; //comp, x1, y1, y2 => x2
int dp1y2[M][M][M]; //comp, x1, x2, y1 => y2 (horizon cut)
int dp2x2[M][M][M]; //comp, x1, y1, y2 => x2 (vertical cut)
char in[M][M];

int getcnt(int x1,int x2,int y1,int y2) {
    return cnt[x2][y2] - cnt[x1-1][y2] - cnt[x2][y1-1] + cnt[x1-1][y1-1];
}
int isfull(int x1,int x2,int y1,int y2) {
    int c = getcnt(x1,x2,y1,y2);
    return c==0 || (c==(x2-x1+1) * (y2-y1+1));
}
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        MSET(dp1, 0);
        MSET(dp2, 0);
        MSET(cnt, 0);
        REP(i,1,n) scanf("%s", in[i]+1);

        //cnt
        REP(i,1,n) REP(j,1,m) {
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + (in[i][j]=='#' ? 1 : 0);
        }

        int cur=1, fr=0, ans=32;
        //stage 0
        REP(x1,1,n)REP(x2,x1,n)REP(y1,1,m) {
            int y2 = max(dp1[fr][x1][x2][y1-1], y1-1);
            while (y2<m && isfull(x1,x2,y1,y2+1)) y2++;
            dp1[fr][x1][x2][y1] = y2;
        }
        REP(x1,1,n)REP(y1,1,m)REP(y2,y1,m) {
            int x2 = max(dp2[fr][x1-1][y1][y2], x1-1);
            while (x2<n && isfull(x1,x2+1,y1,y2)) x2++;
            dp2[fr][x1][y1][y2] = x2;
        }
        if (dp1[fr][1][n][1] >= m) ans = 0;

        REP(i,1,31) {
            if (ans<i) break;
            //dp1
            REP(x1,1,n)REP(x2,x1,n)REP(y1,1,m) {
                int y2 = dp1[fr][x1][x2][y1];
                if (y2<m) y2 = dp1[fr][x1][x2][y2+1];
                dp1[cur][x1][x2][y1] = y2;

                auto check = [&](int y) {
                    int x = dp2[fr][x1][y1][y];
                    if (x<n) x = dp2[fr][x+1][y1][y];
                    return x >= x2;
                };
                y2 = max(dp1y2[x1][x2][y1-1], y1-1);
                while (y2<m && check(y2+1)) y2++;
                dp1y2[x1][x2][y1] = y2;
                dp1[cur][x1][x2][y1] = max(dp1[cur][x1][x2][y1], y2);
            }

            //dp2
            REP(x1,1,n)REP(y1,1,m)REP(y2,y1,m) {
                int x2 = dp2[fr][x1][y1][y2];
                if (x2<n) x2 = dp2[fr][x2+1][y1][y2];
                dp2[cur][x1][y1][y2] = x2;

                auto check = [&](int x) {
                    int y = dp1[fr][x1][x][y1];
                    if (y<m) y = dp1[fr][x1][x][y+1];
                    return y >= y2;
                };
                x2 = max(dp2x2[x1-1][y1][y2], x1-1);
                while (x2<n && check(x2+1)) x2++;
                dp2x2[x1][y1][y2] = x2;
                dp2[cur][x1][y1][y2] = max(dp2[cur][x1][y1][y2], x2);
            }

            if (dp1[cur][1][n][1] >= m) ans = min(ans, i);

            swap(cur, fr);
            MSET(dp1y2, 0);
            MSET(dp2x2, 0);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

