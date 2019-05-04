#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
typedef long long LL;
int t;
LL n,m;
int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld",&n,&m);

        if (m==0) {
            printf("%lld\n",n);
            continue;
        }

        LL ans = n-((5*m-1)/2)+1;
        if (ans < 0) ans = 0;
        printf("%lld\n",ans);
    }
    return 0;
}

