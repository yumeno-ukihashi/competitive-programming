#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,k,in[M];
int main()
{
    while (~scanf("%d%d", &n, &k)) {
        REP(i,1,n) scanf("%d", &in[i]);
        sort(in+1, in+n+1);

        int ans = 2000000000;
        REP(i,k,n) ans = min(ans, in[i]-in[i-k+1]);
        printf("%d\n", ans);
    }
    return 0;
}
