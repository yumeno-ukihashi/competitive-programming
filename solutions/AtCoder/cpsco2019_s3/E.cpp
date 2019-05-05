#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
#define BIT(x) (1<<(x))
using namespace std;
int n,in[M],fr[M][30];
long long ans[M];
int main()
{
    while (~scanf("%d",&n)) {
        MSET(ans, 0);
        REP(i,1,n) scanf("%d",&in[i]);
        REP(i,1,n) {
            REP(j,0,29) {
                fr[i][j] = fr[i-1][j] + ((in[i]&BIT(j)) ? 1 : 0);
                if (fr[i][j]%2==1) {
                    ans[i] += (long long)BIT(j) * (i-fr[i][j]);
                } else {
                    ans[i] += (long long)BIT(j) * fr[i][j];
                }
            }
        }

        REP(i,1,n) printf("%lld\n", ans[i]);
    }
    
    return 0;
}


