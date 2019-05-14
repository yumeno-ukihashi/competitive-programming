#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int in[5], ans=0, mx=0;
    REP(i,0,4) scanf("%d",&in[i]);

    REP(i,0,4) {
        ans += (in[i]+9)/10*10;
        if (in[i]%10)
            mx = max(mx, 10-in[i]%10);
    }
    printf("%d\n", ans-mx);
    
    return 0;
}

