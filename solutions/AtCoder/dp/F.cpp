#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
using namespace std;
int n,m,dp[M][M],dx[M][M],dy[M][M];
char in1[M], in2[M];
int main()
{
    while (~scanf("%s%s",in1+1,in2+1)) {
        n = strlen(in1+1);
        m = strlen(in2+1);
        REP(i,1,n) REP(j,1,m) {
            if (in1[i]==in2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                dx[i][j] = dy[i][j] = -1;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                dx[i][j] = -1;
                dy[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j-1];
                dx[i][j] = 0;
                dy[i][j] = -1;
            }
        }

        string ans = "";
        int x=n, y=m;
        while (x&&y) {
            if (dx[x][y]==-1 && dy[x][y]==-1) {
                ans += in1[x];
            }

            int tx=x, ty=y;
            x += dx[tx][ty];
            y += dy[tx][ty];
        }

        reverse(ans.begin(), ans.end());
        printf("%s\n", ans.c_str());
    }
    
    return 0;
}


