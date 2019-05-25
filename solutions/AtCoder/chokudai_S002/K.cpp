#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
class DSJ {
public:
    int ngroups;
    vector<int> fa,sz,edges;
    DSJ() {}
    DSJ(int _n) {
        ngroups = _n;
        fa = vector<int> (_n+1);
        sz = vector<int> (_n+1, 1);
        edges = vector<int> (_n+1, 0);
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
        edges[y]++;
        if (x==y) return;
        fa[x] = y;
        sz[y] += sz[x];
        edges[y] += edges[x];
        ngroups--;
    }
    int groups() {
        return ngroups;
    }
};
int n,id,A[M],B[M];
map<int,int> mp;
DSJ dsj;
int main()
{
    while (~scanf("%d", &n)) {
        auto getid = [&](int x) {
            if (!mp[x]) mp[x] = ++id;
            return mp[x];
        };

        id = 0;
        mp.clear();
        REP(i,1,n) {
            scanf("%d %d",&A[i],&B[i]);
            A[i] = getid(A[i]);
            B[i] = getid(B[i]);
        }

        int ans = 0;
        dsj = DSJ(id);
        REP(i,1,n) dsj.con(A[i], B[i]);
        REP(i,1,id) if (dsj.find(i) == i) ans += min(dsj.size(i), dsj.edges[i]);
        printf("%d\n", ans);
    }
    return 0;
}
