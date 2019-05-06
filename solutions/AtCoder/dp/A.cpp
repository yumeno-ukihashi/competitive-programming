#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,in[M],dp[M];
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) scanf("%d",&in[i]);
        dp[1] = 0;
        REP(i,2,n) {
            dp[i] = dp[i-1] + abs(in[i]-in[i-1]);
            if (i-2>=1) dp[i] = min(dp[i], dp[i-2] + abs(in[i]-in[i-2]));
        }
        printf("%d\n", dp[n]);
    }
    
    return 0;
}


