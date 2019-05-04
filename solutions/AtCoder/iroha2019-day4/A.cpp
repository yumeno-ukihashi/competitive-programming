#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
typedef tuple<int,int,int,int> T;
int n,in[4][M],len[4];
map<T,bool> dp;
map<T,int> fr;
queue<T> q;
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,0,3) scanf("%d",&len[i]);
        REP(i,0,3) REP(j,1,len[i]) scanf("%d",&in[i][j]);

        fr.clear();
        dp.clear();
        dp[make_tuple(0,0,0,0)] = true;
        q.push(make_tuple(0,0,0,0));

        while (!q.empty()) {
            int step,ar[4],nums[4];
            tie(step,ar[0],ar[1],ar[2]) = q.front();
            ar[3] = step-ar[0]-ar[1]-ar[2];
            q.pop();

            if (step==n) {
                continue;
            }

            REP(out,0,3) {
                ar[out]++;
                REP(i,0,3) nums[i] = i==out ? 0 : in[i][step+1-ar[i]];
                sort(nums, nums+4);
                if (nums[0]==0 && nums[1]==1 && nums[2]==2 && nums[3]==3) {
                    if (!dp[make_tuple(step+1, ar[0], ar[1], ar[2])]) {
                        dp[make_tuple(step+1, ar[0], ar[1], ar[2])] = true;
                        fr[make_tuple(step+1, ar[0], ar[1], ar[2])] = out;
                        q.push(make_tuple(step+1, ar[0], ar[1], ar[2]));
                    }
                }
                ar[out]--;
            }
        }

        int step=n, pos[4] = {n-len[0], n-len[1], n-len[2], n-len[3]};
        if (!dp[make_tuple(n, pos[0], pos[1], pos[2])]) {
            puts("No");
        } else {
            puts("Yes");
            vector<int> out;
            while (step>=1) {
                int f = fr[make_tuple(step, pos[0], pos[1], pos[2])];
                out.push_back(f+1);
                step--;
                pos[f]--;
            }
            reverse(out.begin(), out.end());
            for (int i:out) printf("%d\n", i);
        }
    }
    return 0;
}

