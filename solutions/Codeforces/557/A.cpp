#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,k;
vector<int> pos[M];
int main()
{
    while (~scanf("%d %d", &n, &k)) {
        REP(i,0,n) pos[i].clear();
        REP(i,1,k) {
            int x;
            scanf("%d", &x);
            pos[x].push_back(i);
        }

        int ans = 0;
        REP(i,1,n) REP(j,i-1,i+1) {
            if (j<=0 || j>n) continue;

            bool fail = false;
            int fp = -1;
            if (pos[i].size()) fp = pos[i][0];
            if (fp!=-1) {
                auto it = lower_bound(pos[j].begin(), pos[j].end(), fp);
                if (it!=pos[j].end()) fail = true;
            }
            if (!fail) ans++;
        }
        printf("%d\n", ans);

    }
    return 0;
}
