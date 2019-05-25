#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b,ans;
    while (~scanf("%d", &n)) {
        ans = 0;
        while (n--) {
            scanf("%d %d",&a,&b);
            ans = max(ans, a+b);
        }
        printf("%d\n", ans);
    }
    return 0;
}
