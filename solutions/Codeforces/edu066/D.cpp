#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
int n,k,in[M];
long long dp[M];
int main()
{
    while (~scanf("%d %d", &n, &k)) {
        REP(i,1,n) scanf("%d", &in[i]);

        dp[n+1] = 0;
        for (int i=n; i>=1; i--) dp[i] = dp[i+1] + in[i];
        sort(dp+2, dp+n+1, greater<long long>());

        cout << accumulate(dp+2, dp+k+1, 0LL) + dp[1] << endl;
    }
    return 0;
}
