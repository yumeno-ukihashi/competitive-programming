#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int n,m,w[M],v[M];
long long dp[100005];
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        REP(i,1,n) scanf("%d %d",&w[i],&v[i]);
        MSET(dp, -1);
        dp[0] = 0;
        REP(i,1,n) for (int j=n*1000; j>=v[i]; j--)
            if (dp[j-v[i]] != -1) {
                if (dp[j]==-1) dp[j] = (1LL<<61);
                dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
            }

        int ans = 0;
        REP(i,1,n*1000) if (dp[i]!=-1 && dp[i]<=m) ans = i;
        printf("%d\n", ans);
    }
    
    return 0;
}


