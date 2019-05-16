#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,in[M],fr[M],bk[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        fr[0] = bk[n+1] = 0;
        REP(i,1,n) fr[i] = __gcd(fr[i-1], in[i]);
        for (int i=n; i>=1; i--) bk[i] = __gcd(bk[i+1], in[i]);

        int ans = fr[n];
        REP(i,1,n) {
            ans = max(ans, __gcd(fr[i-1], bk[i+1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
