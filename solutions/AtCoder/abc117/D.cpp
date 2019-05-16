#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
int n,c1[64],c0[64],kb[64];
LL K,dp[64][2][2]; //#, last, onaji
int main()
{
    while (~scanf("%d %lld", &n, &K)) {
        MSET(c0, 0);
        MSET(c1, 0);
        REP(i,1,n) {
            LL x;
            scanf("%lld", &x);
            REP(j,0,60) {
                if((1LL<<j) & x) c1[j]++;
                else c0[j]++;
            }
        }
        REP(i,0,60) kb[i] = ((1LL<<i) & K) ? 1 : 0;

        MSET(dp, -1);
        dp[61][0][1] = 0;
        for (int i=61; i>=1; i--) REP(j,0,1) REP(k,0,1) if (dp[i][j][k]>=0) REP(j2,0,1) {
            if (k==1 && j2>kb[i-1]) continue;
            int k2 = (k==1) && (j2==kb[i-1]) ? 1 : 0;
            
            LL add = 0;
            if (j2==1) add += (1LL<<(i-1)) * c0[i-1];
            else       add += (1LL<<(i-1)) * c1[i-1];
            dp[i-1][j2][k2] = max(dp[i-1][j2][k2], dp[i][j][k] + add);
        }

        LL ans = 0;
        REP(i,0,1)REP(j,0,1) ans = max(ans, dp[0][i][j]);
        printf("%lld\n", ans);
    }
    return 0;
}
