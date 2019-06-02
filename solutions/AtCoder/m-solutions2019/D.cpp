#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10005
using namespace std;
int n,id,c[M],ans[M];
vector<int> e[M];
void dfs(int cur,int fa) {
    ans[cur] = c[++id];
    for (int i:e[cur]) if(i!=fa) dfs(i, cur);
}
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) e[i].clear();
        REP(i,1,n-1) {
            int a,b;
            scanf("%d %d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        REP(i,1,n) scanf("%d", &c[i]);
        sort(c+1, c+n+1, greater<int>());

        id = 0;
        dfs(1, -1);
        printf("%lld\n", accumulate(c+2, c+n+1, 0LL));
        REP(i,1,n) {
            printf("%d%c",ans[i],i==n ? '\n':' ');
        }
    }
    return 0;
}
