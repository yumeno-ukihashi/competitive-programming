#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
int n,m,q;
LL in1[M], in2[M];
int main()
{
    while (~scanf("%d %d %d",&n, &m, &q)) {
        REP(i,1,n) scanf("%lld", &in1[i]);
        REP(i,1,m) scanf("%lld", &in2[i]);
        sort(in1+1, in1+n+1);
        sort(in2+1, in2+m+1);

        while (q--) {
            LL x, ans=(1LL<<61);
            LL a[2]={-1, -1}, b[2]={-1, -1};
            scanf("%lld", &x);

            int p = upper_bound(in1+1, in1+n+1, x) - in1 - 1;
            if (p>=1) a[0] = in1[p];
            p = lower_bound(in1+1, in1+n+1, x) - in1;
            if (p<=n) a[1] = in1[p];

            p = upper_bound(in2+1, in2+m+1, x) - in2 - 1;
            if (p>=1) b[0] = in2[p];
            p = lower_bound(in2+1, in2+m+1, x) - in2;
            if (p<=m) b[1] = in2[p];

            REP(i,0,1) REP(j,0,1) if (a[i]!=-1 && b[j]!=-1) {
                LL mi=0, mx=0;
                mi = min(mi, a[i]-x);
                mi = min(mi, b[j]-x);
                mx = max(mx, a[i]-x);
                mx = max(mx, b[j]-x);

                LL dis = min(abs(mi), abs(mx))*2 + max(abs(mi), abs(mx));
                ans = min(ans, dis);
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}

