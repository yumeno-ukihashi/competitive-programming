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
        REP(i,1,n) for (int j=m; j>=w[i]; j--)
            if (dp[j-w[i]] != -1)
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        printf("%lld\n", *max_element(dp, dp+m+1));
    }
    
    return 0;
}

