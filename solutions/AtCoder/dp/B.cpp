#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m,in[M],dp[M];
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        REP(i,1,n) scanf("%d",&in[i]);
        dp[1] = 0;
        REP(i,2,n) {
            dp[i] = 1000000000;
            REP(j,1,m) if(i-j>=1) dp[i] = min(dp[i], dp[i-j] + abs(in[i]-in[i-j]));
        }
        printf("%d\n", dp[n]);
    }
    
    return 0;
}

