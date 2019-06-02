#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
using LL = long long;
int n,m,in[M];
int fr[M];
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        REP(i,1,n) scanf("%d", &in[i]);

        fr[0] = 0;
        REP(i,1,n) {
            int tt = m-in[i];
            if (in[i]==0) tt=0;
            fr[i] = max(fr[i-1], tt);
        }

        auto check = [&](int x) {
            int x2 = x;
            int mn = 1000000000;
            for (int i=n; i>=1; i--) {
                if (in[i]-mn > x2) {
                    if (m-in[i] > x) return false;
                    x2 = min(x2, x-(m-in[i]));
                    mn = 0;
                }
                mn = min(mn, in[i]);
            }
            return true;
        };


        int ok=m, ng=-1, mid;
        while (abs(ok-ng) > 1) {
            mid = (ok+ng)/2;
            if (check(mid)) ok=mid;
            else ng=mid;
        }
        printf("%d\n", ok);

    }
    return 0;
}
