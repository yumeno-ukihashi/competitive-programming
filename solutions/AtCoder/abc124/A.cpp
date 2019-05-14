#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,m,ans;
    while (~scanf("%d %d",&n,&m)) {
        ans = 0;
        REP(i,1,2) {
            ans += max(n,m);
            if (n==max(n,m)) n--;
            else m--;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
