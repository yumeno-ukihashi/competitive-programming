#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define MOD 1000000007
using namespace std;
typedef long long LL;

LL pw(LL x,LL y) {
    x %= MOD;
    LL tmp=x, re=1;
    while (y) {
        if (y&1) re = re * tmp % MOD;
        tmp = tmp * tmp % MOD;
        y /= 2;
    }
    return re;
}
LL n;
int main()
{
    while (~scanf("%lld",&n)) {
        printf("%lld\n", 8LL*pw(5,n-1) % MOD);
    }
    return 0;
}




