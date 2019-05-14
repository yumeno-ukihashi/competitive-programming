#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,m,x,y;
    while (~scanf("%d %d %d %d",&n,&m,&x,&y)) {
        int ans = x*m + y*n - x*y;
        printf("%d\n", n*m - ans);
    }
    
    return 0;
}

