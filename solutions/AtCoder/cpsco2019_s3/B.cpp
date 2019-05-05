#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m,in[M];
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        REP(i,1,n) scanf("%d",&in[i]);
        sort(in+1, in+n+1, greater<int>());

        int ans = 0;
        int sum = 0;
        REP(i,1,n) {
            sum += in[i];
            ans++;
            if (sum >= m) break;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}


