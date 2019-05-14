#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 25
using namespace std;
int n,m,c;
int B[M], in[M];
int main()
{
    while (~scanf("%d %d %d",&n,&m,&c)) {
        REP(i,1,m) scanf("%d", &B[i]);

        int ans = 0;
        REP(t,1,n) {
            REP(i,1,m) scanf("%d", &in[i]);
            int sum = 0;
            REP(i,1,m) sum += in[i] * B[i];
            if (sum+c > 0) ans++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

