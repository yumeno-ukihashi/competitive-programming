#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
int n,m,ans[M];
vector<P> e[M];
void dfs(int cur,int fa) {
    for (auto i:e[cur]) if (i.first != fa) {
        if (i.second%2 == 1) ans[i.first] = 3-ans[cur];
        else ans[i.first] = ans[cur];
        dfs(i.first, cur);
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        MSET(ans, 0);
        REP(i,1,n) e[i].clear();
        REP(i,1,n-1) {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            e[x].push_back( make_pair(y,z) );
            e[y].push_back( make_pair(x,z) );
        }

        ans[1] = 1;
        dfs(1, -1);
        REP(i,1,n) printf("%d\n", ans[i]-1);
    }
    return 0;
}
