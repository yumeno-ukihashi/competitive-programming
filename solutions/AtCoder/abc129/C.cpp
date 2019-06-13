#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
#define MOD 1000000007
using namespace std;
int n,m,dp[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        set<int> s;
        REP(i,1,m) {
            int x;
            scanf("%d", &x);
            s.insert(x);
        }
        
        MSET(dp, 0);
        dp[0] = 1;
        REP(i,1,n) if (s.find(i)==s.end()) {
            if (i>=1) dp[i] = (dp[i] + dp[i-1]) % MOD;
            if (i>=2) dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
