#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
using P = pair<int,int>;
int n, m;
P in[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        REP(i,1,n) scanf("%d %d", &in[i].first, &in[i].second);
        sort(in+1, in+n+1);

        LL ans = 0;
        REP(i,1,n) {
            ans += (LL)min(m, in[i].second) * in[i].first;
            m -= min(m, in[i].second);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}

