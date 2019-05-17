#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int n,m,cnt[10005];
vector<int> in[10005];
int main()
{
    while (~scanf("%d %d", &m, &n)) {
        REP(i,1,m) in[i].clear();
        REP(i,1,m) {
            int x,y;
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &y);
                in[i].push_back(y);
            }
        }

        bool fail = false;
        REP(i,1,m) REP(j,i+1,m) {
            if (fail) break;

            MSET(cnt, 0);
            for (int k:in[i]) cnt[k]++;
            for (int k:in[j]) cnt[k]++;
            if (*max_element(cnt+1, cnt+n+1) <= 1) fail = true;
        }
        puts(fail ? "impossible" : "possible");
    }
    return 0;
}
