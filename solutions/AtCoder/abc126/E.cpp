#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
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
        x = find(x);
        y = find(y);
        if (x==y) return;
        fa[x] = y;
        sz[y] += sz[x];
        ngroups--;
    }
    int groups() {
        return ngroups;
    }
};
int n,m,X[M],Y[M],Z[M];
DSJ dsj;
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        dsj = DSJ(n);
        REP(i,1,m) scanf("%d %d %d",&X[i],&Y[i],&Z[i]);
        REP(i,1,m) {
            dsj.con(X[i], Y[i]);
        }

        printf("%d\n", dsj.groups());
    }
    return 0;
}
