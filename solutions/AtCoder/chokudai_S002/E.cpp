#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b;
    long long ans;
    while (~scanf("%d", &n)) {
        ans = 0;
        REP(i,1,n) {
            scanf("%d %d",&a,&b);
            ans += min(a/2, b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
