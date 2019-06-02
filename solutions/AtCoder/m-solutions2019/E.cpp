#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3000003
#define MOD 1000003
using namespace std;
using LL = long long;
LL pw(LL x,LL y) {
    LL res=1, tmp=x;
    while (y) {
        if (y&1) res = res*tmp%MOD;
        tmp = tmp*tmp%MOD;
        y /= 2;
    }
    return res;
}
LL fact[M];
LL fct(LL x,LL y) {
    LL res = fact[x];
    if (x-y>=0) res *= pw(fact[x-y], MOD-2);
    return res % MOD;
}
int q;
int main()
{
    fact[0] = 1;
    REP(i,1,M-1) fact[i] = fact[i-1] * i % MOD;
    
    int x,d,n;
    while (~scanf("%d", &q)) {
        while (q--) {
            scanf("%d %d %d",&x,&d,&n);
            x %= MOD;
            d %= MOD;

            if (d==0) {
                printf("%lld\n", pw(x,n));
                continue;
            }

            LL st = x * pw(d, MOD-2) % MOD;
            LL tmp = (MOD-x) * pw(d, MOD-2) % MOD;
            if (n-1>=tmp) {
                puts("0");
                continue;
            }            

            LL ans = pw(d, n) * fct(st+n-1, n) % MOD;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
