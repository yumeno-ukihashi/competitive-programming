#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,sum,x,mx;
    while (~scanf("%d", &n)) {
        sum = 0;
        mx = -1;
        REP(i,1,n) {
            scanf("%d", &x);
            sum += x;
            mx = max(mx, x);
        }
        printf("%d\n", sum - mx/2);
    }
    return 0;
}
