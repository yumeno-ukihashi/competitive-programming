#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
int main()
{
    LL n, in[5];
    while (~scanf("%lld", &n)) {
        REP(i,0,4) scanf("%lld", &in[i]);

        LL ans = 0;
        REP(i,0,4) {
            LL d = n / in[i];
            if (n%in[i]) d++;
            d += i;

            //printf("d=%lld ans=%lld\n",d,ans);
            ans = max(ans+1, d);
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}

