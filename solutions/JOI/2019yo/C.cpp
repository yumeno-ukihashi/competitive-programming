#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,dp[M];
char in[M];
int main()
{
    while (~scanf("%d", &n)) {
        scanf("%s", in+1);
        dp[0] = 0;
        REP(i,1,n) {
            dp[i] = dp[i-1];
            if (i>=2 && in[i]!=in[i-1]) {
                dp[i] = max(dp[i], dp[i-2]+1);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
