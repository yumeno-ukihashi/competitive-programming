#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b,c,d;
    while (~scanf("%d %d %d %d %d", &n,&a,&b,&c,&d)) {
        int ans = (n+a-1)/a*b;
        ans = min(ans, (n+c-1)/c*d);
        printf("%d\n", ans);
    }
    return 0;
}
