#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int ans = 0, mx=0;
        vector<int> dp(n+1, 0);
        REP(i,1,n) dp[i] = dp[i-1] + customers[i-1]*grumpy[i-1];
        REP(i,0,n-1) ans += customers[i] * (1-grumpy[i]);
        
        REP(i,X,n) mx = max(mx, dp[i]-dp[i-X]);
        return ans+mx;
    }
};
