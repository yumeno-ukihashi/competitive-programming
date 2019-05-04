#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 5005
using namespace std;

int n,m,dp[M][M];
char S[M], T[M];
int main()
{
  	while (~scanf("%s %s",S+1,T+1)) {
  		n = strlen(S+1);
  		m = strlen(T+1);
  		REP(i,1,n) REP(j,1,m) {
  			if (S[i] == T[j]) {
  				dp[i][j] = dp[i-1][j-1] + 1;
  			} else {
  				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
  			}
  		}
  		printf("%d\n", dp[n][m]+1);
  	}
    return 0;
}

