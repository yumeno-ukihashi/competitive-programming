#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
using P = pair<int,int>;
int n,cur[M],curpos[M];
int t[M],tpos[M];
vector<P> ans;
void mov(int x,int y) {
    swap(cur[x], cur[y]);
    curpos[cur[x]] = x;
    curpos[cur[y]] = y;
    ans.push_back( make_pair(x,y) );
}
void work(int a,int b) {
    if (abs(a-b)>=n/2) {
        mov(a,b);
        return;
    }

    if (a<=n/2 && b<=n/2) {
        mov(a,n);
        mov(n,b);
    } else if (a<=n/2 && b>n/2) {
        mov(a,n);
        mov(1,n);
        mov(1,b);
        mov(n,1);
    } else if (a>n/2 && b<=n/2) {
        mov(a,1);
        mov(1,n);
        mov(n,b);
        mov(a,1);
    } else {
        mov(a,1);
        mov(1,b);
        mov(a,1);
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        ans.clear();
        REP(i,1,n) {
            scanf("%d", &cur[i]);
            curpos[cur[i]] = i;
        }
        REP(i,1,n) {
            t[i] = i;
            tpos[i] = i;
        }

        REP(i,1,n/2)REP(j,0,1) {
            int to = i + j*(n/2);
            int from = curpos[t[to]];
            if (to==from) continue;

            work(from, to);
        }

        REP(i,1,n) assert(cur[i] == t[i]);
        printf("%d\n", (int)ans.size());
        for (auto i:ans) printf("%d %d\n",i.first,i.second);
    }
    return 0;
}
