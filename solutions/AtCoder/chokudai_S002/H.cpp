#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b;
    while (~scanf("%d", &n)) {
        REP(i,1,n) {
            scanf("%d %d",&a,&b);
            int ans = abs(a-b);
            if (!ans) ans = -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
