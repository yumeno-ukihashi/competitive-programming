#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1000005
#define MOD 1000000007
using namespace std;
using LL = long long;
int n,m;
LL fact[M];
LL pw(LL x,LL y) {
    LL res=1, tmp=x;
    while (y) {
        if (y&1) res = res * tmp % MOD;
        tmp = tmp * tmp % MOD;
        y /= 2;
    }
    return res;
}
LL C(int x,int y) {
    if (y>x) return 0;
    return fact[x] * pw(fact[y], MOD-2) % MOD * pw(fact[x-y], MOD-2) % MOD;
}
int main()
{
    fact[0] = 1;
    REP(i,1,M-1) fact[i] = fact[i-1] * i % MOD;
    
    while (~scanf("%d %d",&n,&m)) {
        if (n==1) {
            puts("1");
            continue;
        }

        LL ans = 0;
        int mo = m%2;
        for (int i=mo; abs(i)<=m; i+=2*n) {
            int b = (m-i)/2;
            ans += C(m, b);
            ans %= MOD;
        }
        for (int i=-2*n+mo; abs(i)<=m; i-=2*n) {
            int b = (m-i)/2;
            ans += C(m, b);
            ans %= MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
