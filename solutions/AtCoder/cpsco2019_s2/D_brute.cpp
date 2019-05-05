#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int dp[105][105];
int main()
{
    dp[0][0] = 0;
    REP(i,0,100) REP(j,0,100) {
        if (i+j==0) continue;
        dp[i][j] = 0;
        REP(i0,0,i) if (j>=i-i0) {
            if (!dp[i-i0][j-(i-i0)])
                dp[i][j] = 1;
            if (i==1 && j==2) {
                printf("%d %d: %d\n",i-i0,j-(i-i0),dp[i-i0][j-i+i0]);
            }
        }
        if (i==3 && j==3) printf("%d\n", dp[i][j]);
        REP(j0,0,j) if (i>=j-j0)
            if (!dp[i-(j-j0)][j-j0])
                dp[i][j] = 1;
    }

    REP(i,1,100) REP(j,1,100)
        if (!dp[i][j])
            printf("%d %d\n",i,j);
    
    return 0;
}




