#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 15
using namespace std;
int n,m,p[M],cnt[M];
vector<int> in[M];
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        REP(i,1,m) {
            in[i].clear();
            int x,y;
            scanf("%d",&x);
            while (x--) {
                scanf("%d", &y);
                in[i].push_back(y);
            }
        }

        REP(i,1,m) scanf("%d", &p[i]);

        int ans = 0;
        REP(i,0,(1<<n)-1) {
            MSET(cnt,0);
            REP(j,1,m) for (int k:in[j]) if((1<<(k-1)) & i) cnt[j]++;
            int cc=0;
            REP(j,1,m) if(cnt[j]%2 == p[j]) cc++;
            if (cc==m) ans++;
        }
        printf("%d\n", ans);

    }
    return 0;
}

