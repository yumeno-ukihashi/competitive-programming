#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;

LL out[55];
bool check(int len,LL a,LL b,LL m) {
    LL tmp = (len==1) ? 1 : (1LL << (len-1-1));
    LL mn = tmp * a;
    LL mx = mn;
    REP(i,2,len) {
        tmp = (len-i-1) < 0 ? 1 : (1LL << (len-i-1));
        mn += tmp;
        if (__lg(m) + max(0,len-i-1) <= 50)
            mx += m * tmp;
        else
            mx += (1LL << 50);
    }
    if (b<mn || b>mx) return false;

    LL cur = mn;
    out[1] = a;
    REP(i,2,len) {
        tmp = (len-i-1) < 0 ? 1 : (1LL << (len-i-1));
        LL nokori = b - cur;
        out[i] = min(nokori/tmp, m-1) + 1;
        cur += min(nokori/tmp, m-1) * tmp;
    }
    return true;
}
int main()
{
    int t, ans;
    LL a,b,m;

    scanf("%d", &t);
    while (t--) {
        ans = -1;
        scanf("%lld %lld %lld",&a,&b,&m);
        REP(i,1,50) if (__lg(a) + max(0,i-2) <= 50) if (check(i,a,b,m)) {
            ans = i;
            break;
        }

        if (ans==-1) puts("-1");
        else {
            LL sum = 0;
            printf("%d ",ans);
            REP(i,1,ans) {
                out[i] = sum + out[i];
                sum += out[i];
                printf("%lld%c", out[i], i==ans ? '\n' : ' ');
            }
        }
    }
    return 0;
}
