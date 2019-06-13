#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int n,sum,in[M];
int main()
{
    while (~scanf("%d", &n)) {
        sum = 0;
        REP(i,1,n) {
            scanf("%d", &in[i]);
            sum += in[i];
        }

        int ans = M;
        REP(t,1,n-1) {
            int s1=0, s2=0;
            REP(i,1,t) s1+=in[i];
            REP(i,t+1,n) s2+=in[i];
            ans = min(ans, abs(s1-s2));
        }
        printf("%d\n", ans);
    }
    return 0;
}
