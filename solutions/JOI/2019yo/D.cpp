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
}dsj;
int n;
pair<int,int> in[M];
bool vis[M];
int main()
{
    while (~scanf("%d", &n)) {
        dsj = DSJ(n);
        MSET(vis, false);
        REP(i,1,n) {
            scanf("%d", &in[i].first);
            in[i].second = i;
        }
        sort(in+1, in+n+1, greater<pair<int,int>> ());

        int cells=0, con=0, ans=0;
        REP(i,1,n) if(in[i].first != 0) {
            int j=i;
            while (j+1<=n && in[j+1].first==in[i].first) j++;

            REP(ki,i,j) {
                int k = in[ki].second;
                cells++;
                vis[k] = true;
                if (k>1 && vis[k-1] && dsj.find(k-1)!=dsj.find(k)) {
                    dsj.con(k-1, k);
                    con++;
                }
                if (k<n && vis[k+1] && dsj.find(k+1)!=dsj.find(k)) {
                    dsj.con(k+1, k);
                    con++;
                }
            }

            ans = max(ans, cells-con);
            i = j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
