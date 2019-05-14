#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n, in[25];
    while (~scanf("%d",&n)) {
        REP(i,1,n) scanf("%d", &in[i]);

        int mx = -1, ans = 0;
        REP(i,1,n) {
            mx = max(mx, in[i]);
            if (in[i]==mx) ans++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

