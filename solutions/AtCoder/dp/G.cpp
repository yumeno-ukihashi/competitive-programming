#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m;
int ind[M], dp[M];
vector<int> e[M];
int dfs(int cur) {
    if (dp[cur]) return dp[cur];
    for (int i:e[cur]) dp[cur] = max(dp[cur], dfs(i));
    dp[cur]++;
    return dp[cur];
}
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        MSET(ind, 0);
        MSET(dp, 0);
        REP(i,1,n) e[i].clear();
        REP(i,1,m) {
            int x,y;
            scanf("%d %d",&x,&y);
            e[x].push_back(y);
            ind[y]++;
        }

        int ans = -1;
        REP(i,1,n) if(ind[i]==0) ans = max(ans, dfs(i));
        printf("%d\n", ans-1);
    }
    
    return 0;
}

