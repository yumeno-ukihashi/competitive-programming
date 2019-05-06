#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,in[M][3],dp[M][3];
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) REP(j,0,2) scanf("%d",&in[i][j]);

        REP(i,1,n) REP(j,0,2) {
            dp[i][j] = 0;
            REP(k,0,2) if(j!=k) {
                dp[i][j] = max(dp[i][j], dp[i-1][k] + in[i][j]);
            }
        }
        printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
    }
    
    return 0;
}

