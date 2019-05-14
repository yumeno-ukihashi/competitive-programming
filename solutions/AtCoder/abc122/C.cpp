#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,q,dp[M];
char in[M];
int main()
{
    while (~scanf("%d %d",&n,&q)) {
        scanf("%s", in+1);
        dp[0] = 0;
        REP(i,1,n) {
            if (i>=2 && in[i]=='C' && in[i-1]=='A')
                dp[i] = dp[i-2] + 1;
            else dp[i] = dp[i-1];
        }

        while (q--) {
            int l,r, ans;
            scanf("%d %d",&l,&r);
            ans = dp[r] - dp[l-1];
            if (l>=2 && in[l]=='C' && in[l-1]=='A') ans--;
            printf("%d\n", ans);
        }
    }
    
    return 0;
}

