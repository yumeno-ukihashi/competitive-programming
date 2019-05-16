#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int n,m,nums[10];
int mch[10] = {-1,2,5,5,4,5,6,3,7,6};
int dp[70005],fr[70005];
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        REP(i,1,m) scanf("%d", &nums[i]);
        sort(nums+1, nums+1+m);

        MSET(dp, -1);
        dp[0] = 0;
        REP(j,1,m) REP(i,1,n)  {
            int i0 = i - mch[nums[j]];
            if (i0>=0 && dp[i0]>=0) {
                if (dp[i0] + 1 >= dp[i]) {
                    dp[i] = dp[i0]+1;
                    fr[i] = nums[j];
                }
            }
        }

        vector<int> digs;
        while (n) {
            digs.push_back(fr[n]);
            n -= mch[fr[n]];
        }
        sort(digs.begin(), digs.end(), greater<int> ());
        for (int i: digs) printf("%d", i); puts("");
    }
    return 0;
}
