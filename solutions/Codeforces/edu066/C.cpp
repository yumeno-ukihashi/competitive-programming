#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int t,n,k,in[M];
int main()
{
    while (~scanf("%d", &t)) {
        while (t--) {
            scanf("%d %d", &n, &k);
            REP(i,1,n) scanf("%d", &in[i]);

            k++;
            auto check = [&](int x){
                REP(i,k,n) {
                    int cent = (in[i] + in[i-k+1]) /2;
                    int mx = max(cent-in[i-k+1], in[i]-cent);
                    if (mx<=x) return true;
                }
                return false;
            };

            auto check2 = [&](int x) {
                REP(i,k,n) {
                    int cent = (in[i] + in[i-k+1]) /2;
                    int mx = max(cent-in[i-k+1], in[i]-cent);
                    if (mx<=x) return cent;
                }
                return -1;
            };

            int ok=1000000000, ng=-1, mid;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng) / 2;
                if (check(mid)) ok = mid;
                else ng = mid;
            }
            printf("%d\n", check2(ok));
        }
    }
    return 0;
}
