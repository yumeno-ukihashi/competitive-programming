#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;

int n,m,in[M];
bool dp[100005];
int main()
{
    while (~scanf("%d%d",&n,&m)) {
        REP(i,1,n) scanf("%d",&in[i]);

        MSET(dp, false);
        REP(i,1,m)REP(j,1,n) {
            if (i>=in[j] && !dp[i-in[j]]) dp[i] = true;
        }
        puts(dp[m]?"First":"Second");
    }
    
    return 0;
}


