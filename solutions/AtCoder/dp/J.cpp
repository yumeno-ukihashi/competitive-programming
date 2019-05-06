#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 305
using namespace std;
int n;
double dp[M][M][M];
double calc(int x,int y,int z) {
    if (x<0 || y<0 || z<0) return 0.0;
    if (dp[x][y][z] != -1) return dp[x][y][z];

    double fp = (double)(n-x-y-z) / n;
    dp[x][y][z] = calc(x-1,y,z)*((double)x/n) + calc(x+1,y-1,z)*((double)y/n) + calc(x,y+1,z-1)*((double)z/n) + 1.0;
    dp[x][y][z] /= (1.0-fp);
    return dp[x][y][z];
}
int main()
{
    while (~scanf("%d",&n)) {
        int c[3] = {0,0,0};
        REP(i,1,n) {
            int x;
            scanf("%d",&x);
            c[x-1]++;
        }

        REP(i,0,n)REP(j,0,n)REP(k,0,n) dp[i][j][k] = -1.0;
        dp[0][0][0] = 0.0;
        printf("%.10f\n", calc(c[0],c[1],c[2]));
    }
    
    return 0;
}


