#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
#define MOD 1000000007
using namespace std;
int n, dp[M][256];
bool ban[256];
char sp[5] = "TAGC";
void init() {
    MSET(ban, false);
    char tmp[5];
    REP(i,0,255) {
        int x = i;
        for (int p=3; p>=0; p--) {
            tmp[p] = sp[x%4];
            x /= 4;
        }

        auto check = [&]() {
            REP(j,2,3) if(tmp[j-2]=='A' && tmp[j-1]=='G' && tmp[j]=='C') return true;
            return false;
        };

        if (check()) ban[i] = true;
        REP(j,0,2) {
            swap(tmp[j], tmp[j+1]);
            if (check()) ban[i] = true;
            swap(tmp[j], tmp[j+1]);
        }
    }
}
int main()
{
    init();
    
    while (~scanf("%d", &n)) {
        MSET(dp, 0);
        dp[0][0] = 1;
        REP(i,0,n-1) REP(j,0,255) if(dp[i][j]) {
            REP(k,0,3) {
                int j2 = ((j*4)&255) + k;
                if (!ban[j2]) {
                    dp[i+1][j2] += dp[i][j];
                    dp[i+1][j2] %= MOD;
                }
            }
        }

        int ans = 0;
        REP(i,0,255) ans = (ans+dp[n][i]) % MOD;
        printf("%d\n", ans);
    }
    
    return 0;
}

