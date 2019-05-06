#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
using namespace std;
int n;
double p[M], dp[M][M];
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) scanf("%lf", &p[i]);
        dp[0][0] = 1.0;
        REP(i,1,n) REP(j,0,i) {
            dp[i][j] = dp[i-1][j] * (1.0-p[i]);
            if (j) dp[i][j] += dp[i-1][j-1] * p[i];
        }

        double ans = 0.0;
        REP(i,(n+1)/2,n) ans += dp[n][i];
        printf("%.10f\n", ans);
    }
    
    return 0;
}


