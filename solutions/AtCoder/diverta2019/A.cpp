#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    int n,m;
    while (~scanf("%d %d",&n,&m)) {
        printf("%d\n", max(0, n-m+1));
    }
    return 0;
}



