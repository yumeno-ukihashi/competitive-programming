#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    int r,g,b,n;
    while (~scanf("%d %d %d %d",&r,&g,&b,&n)) {
        int ans = 0;
        REP(i,0,n)REP(j,0,n) {
            int x = n - i*r - j*g;
            if (x>=0 && x%b==0) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}





