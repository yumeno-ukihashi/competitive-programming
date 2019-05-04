#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 2005
#define MOD 1000000007
using namespace std;
typedef long long LL;
int n,m,bit[M];
LL k,ans,c[M][M],s[2][M],s1[M];
LL dp[64][M];
LL pw(LL x,LL y) {
    x %= MOD;
    LL re=1, tmp=x;
    while (y) {
        if (y&1) re = re*tmp % MOD;
        tmp = tmp*tmp%MOD;
        y /= 2;
    }
    return re;
}
void getbit() {
    LL x = k;
    m = 0;
    while (x) {
        bit[++m] = x%2;
        x /= 2;
    }
    reverse(bit+1, bit+m+1);
}
int main()
{
    c[0][0] = 1;
    REP(i,1,M-1) {
        c[i][0] = 1;
        REP(j,1,i) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    }

    REP(i,0,M-1) REP(j,0,i) {
        s[j%2][i] = (s[j%2][i]+c[i][j]) % MOD;
    }

    while (~scanf("%d %lld",&n,&k)) {
        ans = pw(k+1, n);
        getbit();

        MSET(dp, 0);
        dp[0][n] = 1;
        REP(i,0,m-1) REP(j,0,n) if (dp[i][j]) {
            REP(j1,0,j) {
                if (j1 && bit[i+1]==0) break;
                int nj = bit[i+1]==0 ? j : j1;
                
                dp[i+1][nj] += c[j][j1] * s[j1%2][n-j] % MOD * dp[i][j];
                dp[i+1][nj] %= MOD;
            }
        }
        
        REP(i,0,n) ans = (ans - dp[m][i]) % MOD;
        if (ans<0) ans += MOD;
        printf("%lld\n", ans);
    }
    return 0;
}

