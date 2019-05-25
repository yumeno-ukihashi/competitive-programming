#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,x,y;
    while (~scanf("%d", &n)) {
        while (n--) {
            scanf("%d %d",&x,&y);
            printf("%lld\n", (long long)x*y);
        }
    }
    return 0;
}
