#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
typedef long long LL;
int n,m;
LL l;
int main()
{
    while (~scanf("%d %d %lld",&n,&m,&l)) {
        LL ans = l*m;
        REP(i,1,n) {
            LL x,y;
            scanf("%lld %lld",&x,&y);
            ans = min(ans, x+y*m);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

