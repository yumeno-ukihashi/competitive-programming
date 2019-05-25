#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int a,b;
    while (~scanf("%d %d", &a,&b)) {
        if (a>=13) printf("%d\n", b);
        else if(a>=6) printf("%d\n", b/2);
        else puts("0");
    }
    return 0;
}
