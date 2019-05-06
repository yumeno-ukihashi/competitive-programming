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
