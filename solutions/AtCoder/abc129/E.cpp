#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
#define MOD 1000000007
using namespace std;
using LL = long long;
int n;
LL pw2[M],pw3[M];
char in[M];
int main()
{
    pw2[0] = 1;
    REP(i,1,M-1) pw2[i] = pw2[i-1] * 2 % MOD;

    pw3[0] = 1;
    REP(i,1,M-1) pw3[i] = pw3[i-1] * 3 % MOD;

    while (~scanf("%s", in+1)) {
        n = strlen(in+1);

        LL ans = 0;
        int pre = 0;
        REP(i,1,n) if(in[i]=='1') {
            int noko = n-i;
            ans += pw2[pre] * pw3[noko];
            ans %= MOD;
            pre++;
        }
        ans += pw2[pre];
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
