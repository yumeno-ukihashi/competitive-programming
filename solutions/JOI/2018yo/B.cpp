#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,in[105];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        in[n+1] = 0;

        int ans=1, fr0=0;
        REP(i,1,n+1) if(in[i]==0) {
            ans = max(ans, i-fr0);
            fr0 = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
