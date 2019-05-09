#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,m;
    while (~scanf("%d %d",&n,&m)) {
        if (m==0) puts("1");
        else if (m==n) puts("0");
        else printf("%d\n", min(n-m, m));
    }
    
    return 0;
}




