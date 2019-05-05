#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 5005
#define INF (1LL<<61)
using namespace std;
int n;
long long dp[M][M];
vector<pair<int,int>> e[M];
void dfs(int cur) {
    dp[cur][0] = 0;
    REP(i,1,n) dp[cur][i] = INF;

    vector<int> w;
    vector<long long> cost;
    for (auto i: e[cur]) {
        int t = i.first;
        dfs(t);

        w.clear();
        cost.clear();
        
        REP(j,1,n) if (dp[t][j]!=INF) {
            if (dp[t][j] == i.second) {
                w.push_back(j+1);
                cost.push_back(dp[t][j]);
            }
            if (dp[t][j] >  i.second) {
                w.push_back(j);
                cost.push_back(i.second);
                break;
            }
            w.push_back(j);
            cost.push_back(dp[t][j]);
        }
        if (!cost.size() || cost.back() != i.second) {
            int nxt = 1;
            if (w.size()) nxt = w.back() + 1;
            w.push_back(nxt);
            cost.push_back(i.second);
        }


        int sz = w.size();
        for (int k=n; k>=0; k--) REP(j,0,sz-1) if (k>=w[j]) {
            dp[cur][k] = min(dp[cur][k], dp[cur][k-w[j]] + cost[j]);
        }
    }
}
int main()
{
    while (~scanf("%d",&n)) {
        assert(n<=300);
        REP(i,1,n) e[i].clear();
        REP(i,1,n-1) {
            int p,h;
            scanf("%d %d", &p, &h);
            e[p+1].push_back( make_pair(i+1, h) );
        }

        dfs(1);

        int ans = 0;
        REP(i,1,n) if (dp[1][i] != INF) ans = i;
        printf("%d\n", ans+1);
    }
    
    return 0;
}

