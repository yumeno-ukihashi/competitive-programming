#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
int n,m;
int cnt[M], in1[M], in2[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        REP(i,1,n) scanf("%d", &in1[i]);
        REP(i,1,m) scanf("%d", &in2[i]);

        sort(in1+1, in1+n+1);
        sort(in2+1, in2+m+1);

        MSET(cnt, 0);
        LL ans = 0;

        if (*min_element(in2+1,in2+m+1) > *max_element(in1+1,in1+n+1)) {
            cnt[n] = m-1;
            cnt[n-1] = 1;
            REP(i,1,m) ans += in2[i];
        } else if (*min_element(in2+1,in2+m+1) == *max_element(in1+1,in1+n+1)) {
            cnt[n] = m;
            REP(i,1,m) ans += in2[i];
        } else {
            puts("-1");
            continue;
        }

        REP(i,1,n) {
            ans += (LL)in1[i] * (m-cnt[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

