#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,in[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        int ans = 0;
        REP(i,1,n) ans = __gcd(ans, in[i]);
        printf("%d\n", ans);
    }
    return 0;
}
