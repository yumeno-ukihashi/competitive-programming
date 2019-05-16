#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 25
using namespace std;
int n,c[M],v[M];
int main()
{
    while (~scanf("%d", &n)) {
        int ans = 0;
        REP(i,1,n) scanf("%d", &v[i]);
        REP(i,1,n) scanf("%d", &c[i]);
        REP(ch, 0, (1<<n)-1) {
            int x=0, y=0;
            REP(i,1,n) if ((1<<(i-1)) & ch) {
                x += v[i];
                y += c[i];
            }
            ans = max(ans, x-y);
        }
        printf("%d\n", ans);
    }
    return 0;
}
