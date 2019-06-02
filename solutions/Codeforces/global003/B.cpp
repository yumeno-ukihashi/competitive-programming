#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,m,k,ta,tb,a[M],b[M];
int main()
{
    while (~scanf("%d %d %d %d %d", &n,&m,&ta,&tb,&k)) {
        REP(i,1,n) scanf("%d", &a[i]);
        REP(i,1,m) scanf("%d", &b[i]);

        if (k>=m || k>=n) {
            puts("-1");
            continue;
        }

        int ans = 1;
        REP(i,0,k) {
            int pos = lower_bound(b+1, b+m+1, a[i+1]+ta) - b;
            pos += k-i;
            ans = max(ans, pos);
        }

        if (ans>m) puts("-1");
        else printf("%d\n", b[ans]+tb);
    }
    return 0;
}
