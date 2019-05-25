#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
#define MOD 1000000007
using namespace std;
using LL = long long;
int n,m,k;
LL fact[M],ans;
LL pw(LL x,LL y) {
    LL res=1, tmp=x;
    while (y) {
        if (y&1) res = (res*tmp)%MOD;
        tmp = (tmp*tmp)%MOD;
        y/=2;
    }
    return res;
}
int main()
{
    fact[0] = 1;
    REP(i,1,M-1) fact[i] = (fact[i-1]*i)%MOD;
    
    while (~scanf("%d %d %d", &n,&m,&k)) {
        ans = 0;
        if (k==1) {
            puts("0");
            continue;
        }

        REP(dis,1,n-1) {
            LL tmp = (LL)m * m % MOD * (n-dis) % MOD;
            tmp = tmp * fact[n*m-2] % MOD * pw(fact[k-2], MOD-2) % MOD * pw(fact[n*m-k], MOD-2) % MOD;
            tmp = tmp * dis % MOD;
            ans = (ans + tmp) % MOD;
        }

        REP(dis,1,m-1) {
            LL tmp = (LL)n * n % MOD * (m-dis) % MOD;
            tmp = tmp * fact[n*m-2] % MOD * pw(fact[k-2], MOD-2) % MOD * pw(fact[n*m-k], MOD-2) % MOD;
            tmp = tmp * dis % MOD;
            ans = (ans + tmp) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
