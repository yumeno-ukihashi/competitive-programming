#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
using LL = long long;
int n,m,in[M];
LL dp[M],dp2[M];
P card[M];
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        REP(i,1,n) scanf("%d", &in[i]);
        REP(i,1,m) scanf("%d %d",&card[i].second,&card[i].first);
        sort(in+1, in+n+1);
        sort(card+1, card+m+1, greater<P>());

        dp[0] = 0;
        REP(i,1,n) dp[i] = dp[i-1] + in[i];

        MSET(dp2, -1);
        dp2[0] = 0;
        int pos=1;
        REP(i,1,m) {
            if (pos>n) break;
            REP(j,pos,min(pos+card[i].second-1, n))
                dp2[j] = dp2[j-1] + card[i].first;
            pos += card[i].second;
        }

        LL ans = dp[n];
        REP(i,1,n) if(dp2[i]!=-1) ans = max(ans, dp2[i] + dp[n]-dp[i]);

        printf("%lld\n", ans);
    }
    return 0;
}
