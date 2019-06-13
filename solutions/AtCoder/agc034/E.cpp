#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 2005
#define INF 2000000000
using namespace std;
using P = pair<int,int>;
int n,cnt[M],dp[M],dsum[M];
char s[M];
vector<int> e[M];
void check(int cur,int fa) {
    vector<P> tmp;
    cnt[cur] = s[cur]=='1' ? 1:0;
    dsum[cur] = 0;

    for (int i:e[cur]) if(i!=fa) {
        check(i, cur);
        cnt[cur] += cnt[i];
        dsum[cur] += dsum[i]+cnt[i];
        if (cnt[i]) tmp.push_back( make_pair(dsum[i]+cnt[i], dp[i]+cnt[i]) );
    }

    sort(tmp.begin(), tmp.end(), greater<P> ());

    if (tmp.size()) {
        int s1 = tmp[0].second;
        int s2 = 0;
        REP(i,1,(int)tmp.size()-1) s2 += tmp[i].first;

        if (s1<=s2) dp[cur] = dsum[cur]%2;
        else dp[cur] = s1 - s2;
    } else {
        dp[cur] = 0;
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,0,n) e[i].clear();
        scanf("%s", s+1);
        REP(i,1,n-1) {
            int x,y;
            scanf("%d %d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }

        int ans = INF;
        REP(root, 1, n) {
            check(root, -1);
            if (dp[root] == 0) {
                ans = min(ans, dsum[root]/2);
            }
        }
        printf("%d\n", ans==INF ? -1 : ans);
    }
    return 0;
}
