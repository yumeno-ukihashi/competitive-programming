#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
int n,in[M];
int main()
{
    while (~scanf("%d", &n)) {
        int cnt = 0;
        REP(i,1,n) {
            scanf("%d", &in[i]);
            if (in[i]<0) {
                cnt ++;
                in[i] *= -1;
            }
        }

        LL ans = accumulate(in+1, in+n+1, 0LL);
        if (cnt%2) {
            ans -= *min_element(in+1, in+n+1) * 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
