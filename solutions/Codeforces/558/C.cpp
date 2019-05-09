#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
#define INF 1000000000
using namespace std;
using P = pair<int,int>;
int n;
P in[M];
P operator - (P a, P b) {
    return make_pair(a.first-b.first, a.second-b.second);
}
P yaku(P x) {
    int g = __gcd(x.first, x.second);
    x.first /= g;
    x.second /= g;
    if (x.second < 0) {
        x.first *= -1;
        x.second *= -1;
    }
    return x;
}
int sgn(int x) {
    if (x==0) return 0;
    if (x>0) return 1;
    return -1;
}
P findo(P v,P a) {
    if (v.first) {
        int d = a.first / v.first;
        a.first -= v.first * d;
        a.second -= v.second * d;
        while (a.first < 0) {
            a.first += v.first * sgn(v.first);
            a.second += v.second * sgn(v.first);
        }
    } else if (v.second) {
        int d = a.second / v.second;
        a.first -= v.first * d;
        a.second -= v.second * d;
        while (a.second < 0) {
            a.first += v.first;
            a.second += v.second;
        }
    }
    return a;
}
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) scanf("%d %d",&in[i].first, &in[i].second);

        map<pair<P,P>,bool> vis;
        map<P,int> cnt;
        REP(i,1,n) REP(j,i+1,n) {
            P r = yaku(in[i]-in[j]);
            P o = findo(r, in[i]);
            if (!vis[make_pair(r,o)]) {
                vis[make_pair(r,o)] = true;
                cnt[r]++;
            }
            
        }

        long long ans = 0;
        int prefix = 0;
        for (auto i: cnt) {
            //printf("(%d,%d) = %d\n",i.first.first,i.first.second,i.second);
            ans += i.second * prefix;
            prefix += i.second;
        }
        cout << ans << endl;
    }
    return 0;
}





