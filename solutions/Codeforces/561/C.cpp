#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,in[M];

int cnt(int st,int ed) {
    int p1 = lower_bound(in+1, in+n+1, st) - in;
    int p2 = upper_bound(in+1, in+n+1, ed) - in - 1;
    if (p1<=p2) return p2-p1+1;
    return 0;
}

int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        sort(in+1, in+n+1);
        
        long long ans = 0;
        REP(i,1,n) {
            if (in[i]>=0) ans += cnt(in[i]+1, in[i]*2);
            else if (in[i]<0) ans += cnt(in[i]*2, in[i]-1);
        }
        REP(i,1,n) {
            if (in[i]>0) ans += cnt(-in[i]*2, -in[i]);
            else if (in[i]<0) ans += cnt(-in[i]+1, -in[i]*2);
        }
        cout << ans << endl;
    }
    return 0;
}
