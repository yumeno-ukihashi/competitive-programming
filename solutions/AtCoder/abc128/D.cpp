#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int n,k,in[M];
int main()
{
    while (~scanf("%d %d", &n,&k)) {
        REP(i,1,n) scanf("%d", &in[i]);

        int ans = 0;
        REP(i,0,n) REP(j,0,n) if(i+j<=n && i+j<=k) {
            int s = accumulate(in+1, in+1+i, 0);
            s += accumulate(in+n+1-j, in+n+1, 0);
            int noko = k-i-j;
            priority_queue<int,vector<int>,greater<int>> q;
            REP(t,1,i) q.push(in[t]);
            REP(t,n-j+1,n) q.push(in[t]);

            while (noko && !q.empty() && q.top()<0) {
                s -= q.top();
                q.pop();
                noko--;
            }
            ans = max(ans, s);
        }
        printf("%d\n", ans);
    }
    return 0;
}

