#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
struct DSJ {
  int fa[M], sz[M];
  DSJ () {}
  DSJ (int _n) {
    REP(i,0,_n) fa[i]=i, sz[i]=1;
  }
  int find(int x) {
    return x==fa[x] ? x : fa[x]=find(fa[x]);
  }
  void con(int x,int y) {
    x = find(x);
    y = find(y);
    if (x!=y) {
      fa[x] = y;
      sz[y] += sz[x];
    }
  }
  int size(int x) {
    return sz[find(x)];
  }
}d0, d1;
int n;
bool vis[M];
vector<int> e0p[M];

int main()
{
  while (~scanf("%d",&n)) {
    MSET(vis, false);
    REP(i,0,n) e0p[i].clear();
    d0 = DSJ(n);
    d1 = DSJ(n);
    
    REP(i,1,n-1) {
      int x,y,z;
      scanf("%d %d %d",&x,&y,&z);
      if (z==0) {
        d0.con(x,y);
      } else {
        d1.con(x,y);
      }
    }

    long long ans = 0;
    REP(i,1,n) {
      if (d0.find(i) == i) {
        ans += (long long)d0.size(i) * (d0.size(i)-1);
      }
      if (d1.find(i) == i) {
        ans += (long long)d1.size(i) * (d1.size(i)-1);
      }
    }

    REP(i,1,n) e0p[d0.find(i)].push_back(i);
    REP(i,1,n) if (i == d0.find(i)) {
      int cnt = 0;
      vector<int> tmp;
      for (int j:e0p[i]) if (!vis[d1.find(j)]) {
        vis[d1.find(j)] = true;
        cnt += d1.size(j)-1;
        ans -= d1.size(j)-1;
        tmp.push_back(d1.find(j));
      }

      ans += (long long)d0.size(i) * cnt;

      for (int j: tmp) vis[j] = false;
    }
    printf("%lld\n", ans);

  }
  return 0;
}


