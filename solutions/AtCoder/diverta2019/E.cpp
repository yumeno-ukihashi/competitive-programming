#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 500005
#define MX 1048576
#define MOD 1000000007
using namespace std;
using LL = long long;
int n,in[M];
LL pw[M];
vector<int> pos[MX];
int find_cnt(int p1,int p2,int num) {
    auto it1 = upper_bound(pos[num].begin(), pos[num].end(), p1);
    auto it2 = lower_bound(pos[num].begin(), pos[num].end(), p2) - 1;
    if (it1<=it2) return it2-it1+1;
    return 0;
}
int main()
{
    pw[0] = 1;
    REP(i,1,M-1) pw[i] = (pw[i-1]*2) % MOD;
    
    while (~scanf("%d",&n)) {
        REP(i,0,MX-1) pos[i].clear();
        REP(i,1,n) scanf("%d", &in[i]);
        REP(i,2,n) in[i] ^= in[i-1];
        REP(i,1,n) pos[in[i]].push_back(i);

        //REP(i,1,n) printf("%d ",in[i]); puts("");

        LL ans = 0;
        REP(i,1,MX-1) if (in[n]==0 || in[n]==i) {
            LL frsum = 0;
            LL frdp = 0;
            LL dp = 0;

            REP(j,0,(int)pos[i].size()-1) {
                int fri = j==0 ? 0 : pos[i][j-1];
                int c0 = find_cnt(fri, pos[i][j], 0);
                
                frdp = (frdp + frsum * c0) % MOD;
                dp = (frdp + 1) % MOD;
                frsum = (frsum + dp) % MOD;
            }
           
            if (in[n]==0) {
                ans += frsum;
                ans %= MOD;
            } else {
                ans += dp;
                ans %= MOD;
            }
        }

        if (in[n]==0) {
            int len = 0;
            REP(i,1,n-1) if(in[i]==0) len++;
            ans += pw[len];
            ans %= MOD;
        }


        printf("%lld\n", ans);
    }
    return 0;
}

