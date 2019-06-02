#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        for (int i=0; i<(int)heights.size(); i++)
            if (heights[i] != tmp[i])
                ans++;
        return ans;
    }
};
