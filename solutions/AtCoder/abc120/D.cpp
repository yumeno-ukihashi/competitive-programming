#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
using P = pair<int,int>;
class DSJ {
public:
    int ngroups;
    vector<int> fa,sz;
    DSJ() {}
    DSJ(int _n) {
        ngroups = _n;
        fa = vector<int> (_n+1);
        sz = vector<int> (_n+1, 1);
        REP(i,0,_n) fa[i] = i;
    }
    int find(int x) {
        return x==fa[x] ? x : fa[x]=find(fa[x]);
    }
    int size(int x) {
        return sz[find(x)];
    }
    void con(int x,int y) {
        x = fa[x];
        y = fa[y];
        if (x==y) return;
        fa[x] = y;
        sz[y] += sz[x];
        ngroups--;
    }
    int groups() {
        return ngroups;
    }
};
int n,m;
P in[M];
LL ans[M];
DSJ dsj;
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        dsj = DSJ(n);
        LL sum = (LL)n*(n-1)/2LL;
        REP(i,1,m) scanf("%d %d",&in[i].first,&in[i].second);
        
        ans[m] = sum;
        for (int i=m; i>=1; i--) {
            int x = dsj.find(in[i].first);
            int y = dsj.find(in[i].second);
            if (x!=y) {
                sum -= (LL)dsj.size(x) * dsj.size(y);
                dsj.con(x,y);
            }
            ans[i-1] = sum;
        }

        REP(i,1,m) printf("%lld\n", ans[i]);
    }
    
    return 0;
}

