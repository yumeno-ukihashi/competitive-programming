#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,m,a1,a2;
    while (~scanf("%d %d", &n,&m)) {
        a1 = 1;
        a2 = n;
        REP(i,1,m) {
            int x,y;
            scanf("%d %d",&x,&y);
            a1 = max(a1, x);
            a2 = min(a2, y);
        }
        printf("%d\n", max(0, a2-a1+1));
    }
    return 0;
}
