#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
using LL = long long;
int n,in[M],ll[M],rr[M];
int lmax[M], rmax[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);

        lmax[0] = rmax[n+1] = -1;
        REP(i,1,n) lmax[i] = max(lmax[i-1], in[i]);
        for (int i=n; i>=1; i--) rmax[i] = max(rmax[i+1], in[i]);

        REP(i,1,n) {
            int ok=i, ng=0, mid;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng) / 2;
                if (lmax[mid] >= in[i]) ok = mid;
                else ng = mid;
            }
            ll[i] = ok;
        }

        for (int i=n; i>=1; i--) {
            int ok=i, ng=n+1, mid;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng) / 2;
                if (rmax[mid] >= in[i]) ok = mid;
                else ng = mid;
            }
            rr[i] = ok;
        }
        //REP(i,1,n) printf("%d %d\n",ll[i],rr[i]);

        
        LL ans = 1LL << 61;
        REP(i,1,n) {
            int len = max(i-ll[i], rr[i]-i);
            if(len) ans = min(ans, (LL)in[i]/len);
        }
        cout << ans << endl;
    }
    return 0;
}

