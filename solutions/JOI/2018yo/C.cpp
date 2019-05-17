#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 30
using namespace std;
int n,m,in[M][M];
int main()
{
    while (~scanf("%d %d", &n,&m)) {
        REP(i,1,n)REP(j,1,m) scanf("%d", &in[i][j]);
        
        int ans = 2000000000;
        REP(i,1,n)REP(j,1,m) {
            int sum = 0;
            REP(ii,1,n)REP(jj,1,m) {
                int d = min(abs(ii-i), abs(jj-j));
                sum += d * in[ii][jj];
            }
            ans = min(ans, sum);
        }

        printf("%d\n", ans);
    }
    return 0;
}
