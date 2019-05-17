#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 500005
using namespace std;
bool fail;
int t,n,cnt,ans[M];
vector<int> e[M];
int dfs(int cur) {
    reverse(e[cur].begin(), e[cur].end());
    int frmn = 200000000;
    for (int i:e[cur]) {
        if (frmn < i) {
            fail = true;
            break;
        }
        frmn = dfs(i);
    }
    ans[cur] = ++cnt;
    return min(cur, frmn);
}
int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP(i,0,n+1) e[i].clear();
        REP(i,0,n+1) ans[i] = 0;
        REP(i,1,n) {
            int x;
            scanf("%d",&x);
            if (x==-1) x = i+1;
            e[x].push_back(i);
        }

        cnt = 0;
        fail = false;
        dfs(n+1);
        if (fail) puts("-1");
        else REP(i,1,n) printf("%d%c", ans[i], i==n?'\n':' ');
    }
    return 0;
}
