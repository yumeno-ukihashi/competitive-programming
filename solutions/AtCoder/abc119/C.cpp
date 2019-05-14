#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10
using namespace std;
int ans,n,in[M],len[4];
void dfs(int d,int a,int b,int c,int sum) {
    if (d>n) {
        if (a>0 && b>0 && c>0) {
            ans = min(ans, sum + abs(len[1]-a) + abs(len[2]-b) + abs(len[3]-c));
        }
        return;
    }
    
    dfs(d+1, a, b, c, sum);
    dfs(d+1, a+in[d], b, c, sum + (a==0?0:10));
    dfs(d+1, a, b+in[d], c, sum + (b==0?0:10));
    dfs(d+1, a, b, c+in[d], sum + (c==0?0:10));
}
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,3) scanf("%d", &len[i]);
        REP(i,1,n) scanf("%d", &in[i]);

        ans = 2000000000;
        dfs(1, 0, 0, 0, 0);
        printf("%d\n", ans);
    }
    
    return 0;
}

