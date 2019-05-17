#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using P = pair<int,int>;
using LL = long long;
int n,m,val[M],mnl[M];
P in[M];
LL dp[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        REP(i,1,n) scanf("%d", &val[i]);
        REP(i,1,m) scanf("%d %d",&in[i].second,&in[i].first);
        sort(in+1, in+m+1);

        mnl[m+1] = 2000000000;
        for (int i=m; i>=1; i--) mnl[i] = min(mnl[i+1], in[i].second);

        int pos=1;
        dp[0] = 0;
        REP(i,1,n) {
            while (pos<=m && in[pos].first<i) pos++;
            dp[i] = dp[i-1];
            
            if (mnl[pos]>i)
                dp[i] += val[i];
            else
                dp[i] = max(dp[i], dp[mnl[pos]-1] + val[i]);
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
