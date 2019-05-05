#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 35
using namespace std;

int n,k,in[M];
int ans;
void dfs(int id,int cnt,int sum) {
    if (n-id+1 < k-cnt) return;
    if (cnt==k) {
        int x=sum, tmp=0;
        while (x) {
            int y = x%10;
            tmp += y>=5 ? y-4 : y;
            x /= 10;
        }
        ans = min(ans, tmp);
        return;
    }
    if (id > n) return;

    REP(i,id,n) dfs(i+1, cnt+1, sum+in[i]);
}
int main()
{
    while (~scanf("%d %d",&n,&k)) {
        ans = 1000000000;
        REP(i,1,n) scanf("%d",&in[i]);
        dfs(1,0,0);
        printf("%d\n", ans);
    }
    return 0;
}

