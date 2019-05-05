#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 305
#define MOD 1000000007
using namespace std;
using LL = long long;
LL c[M][M], dp[M][M];
int main()
{
    REP(i,0,M-1) {
        c[i][0] = 1;
        REP(j,1,i) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }

    REP(i,1,M-1) {
        if(i>1) dp[i][1] = 1;
        REP(j,2,i-1) {
            dp[i][j] = j*dp[i-1][j] + (i-j)*dp[i-1][j-1] + (i-1)*dp[i-2][j-1];
            dp[i][j] %= MOD;
        }
    }

    int n,x,y;
    while (~scanf("%d %d %d",&n,&x,&y)) {
        long long ans = c[n][n-x-y];
        if (x+y!=0) ans *= dp[x+y][x];
        printf("%lld\n", ans%MOD);
    }
    
    return 0;
}


