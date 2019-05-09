#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
#define INF 1000000000
using namespace std;
int n,m[2],fail[2][M];
char in[M],s[2][M];
int dp[M][52][52];

void kmp(char str[],int len,int f[]) {
    f[1] = 0;
    int j = 0;
    REP(i,2,len) {
        while (j>0 && str[i]!=str[j+1]) j = f[j];
        if (str[i]==str[j+1]) j++;
        f[i] = j;
    }
}

int main()
{
    while (~scanf("%s",in+1)) {
        n = strlen(in+1);
        REP(i,0,1) {
            scanf("%s", s[i]+1);
            m[i] = strlen(s[i]+1);
            kmp(s[i], m[i], fail[i]);
        }
        
        REP(i,0,n)REP(j,0,m[0])REP(k,0,m[1]) dp[i][j][k] = -INF;
        dp[0][0][0] = 0;
        REP(i,0,n-1)REP(j,0,m[0])REP(k,0,m[1]) if (dp[i][j][k] != -INF) {
            //printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
            char c0='a', c1='z';
            if (in[i+1]!='*') c0 = c1 = in[i+1];
            for (char c=c0; c<=c1; c++) {
                int j1 = j;
                while (j1 && s[0][j1+1]!=c) j1 = fail[0][j1];
                if (s[0][j1+1]==c) j1++;
                int k1 = k;
                while (k1 && s[1][k1+1]!=c) k1 = fail[1][k1];
                if (s[1][k1+1]==c) k1++;

                int cost = 0;
                if (j1==m[0]) cost++;
                if (k1==m[1]) cost--;
                dp[i+1][j1][k1] = max(dp[i+1][j1][k1], dp[i][j][k]+cost);
            }
        }

        int ans = -INF;
        REP(j,0,m[0])REP(k,0,m[1]) ans = max(ans, dp[n][j][k]);
        printf("%d\n", ans);
    }
    
    return 0;
}




