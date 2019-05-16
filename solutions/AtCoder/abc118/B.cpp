#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 35
using namespace std;
int n,m;
vector<int> suko[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        REP(i,0,n) suko[i].clear();
        REP(i,1,n) {
            int x,y;
            scanf("%d",&x);
            REP(j,1,x) {
                scanf("%d", &y);
                suko[i].push_back(y);
            }
        }

        auto check = [&](int x) {
            REP(i,1,n) {
                auto it = find(suko[i].begin(), suko[i].end(), x);
                if (it == suko[i].end()) return false;
            }
            return true;
        };
        int ans = 0;
        REP(i,1,m) if (check(i)) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
