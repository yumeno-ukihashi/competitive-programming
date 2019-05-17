#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,k,a;
    while (~scanf("%d %d", &n,&k)) {
        a = (n-k)/2;
        REP(i,1,n) printf("%d", i%(a+1)==0 ? 1 : 0);
        puts("");
    }
    return 0;
}
