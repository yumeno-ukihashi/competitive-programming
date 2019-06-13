#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using P = pair<int,int>;
int n,m,s[M],top,rr[M],step[M][20];
P in[M], ask[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        auto find_r = [&](int x){
            int ng=-1, ok=top, mid;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng)/2;
                if (in[s[mid]].second >= x) ok = mid;
                else ng = mid;
            }
            return ok;
        };
        auto find_l = [&](int x){
            int ok=-1, ng=top, mid;
            while (abs(ok-ng) > 1) {
                mid = (ok+ng)/2;
                if (in[s[mid]].first <= x) ok = mid;
                else ng = mid;
            }
            return ok;
        };
        REP(i,1,n) scanf("%d %d",&in[i].first, &in[i].second);
        REP(i,1,m) scanf("%d %d",&ask[i].first,&ask[i].second);

        sort(in+1, in+n+1, [](P a,P b){
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        top = 0;
        REP(i,1,n) {
            while (top && in[i].first<=in[s[top-1]].first) top--;
            s[top++] = i;
        }
        rr[top-1] = top-1;
        for (int i=top-2; i>=0; i--) {
            if (in[s[i]].second >= in[s[i+1]].first)
                rr[i] = rr[i+1];
            else
                rr[i] = i;
        }

        for (int i=top-1; i>=0; i--) {
            step[i][0] = find_l(in[s[i]].second);
        }
        REP(i,1,19)REP(j,0,top-1) step[j][i] = step[step[j][i-1]][i-1];

        //
        REP(i,1,top-1) assert(in[s[i]].first > in[s[i-1]].first);
        REP(i,1,top-1) assert(in[s[i]].second > in[s[i-1]].second);
        

        REP(i,1,m) {
            int x = find_l(ask[i].first);
            int y = find_r(ask[i].second);
            if (x==-1 || y==top) puts("-1");
            else if (rr[x]<y) puts("-1");
            else {
                //assert(x<=y);
                y = max(y,x);
                int ans = 1;
                for (int j=19; j>=0; j--) if (step[x][j]<y) {
                    x = step[x][j];
                    ans += (1<<j);
                }
                if (x!=y) ans++;
                printf("%d\n", ans);
            }
        }
        
    }
    return 0;
}
