#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int x,y,z;
    while (~scanf("%d %d %d", &x,&y,&z)) {
        if (x > y+z) puts("+");
        else if (y > x+z) puts("-");
        else if(z==0) puts("0");
        else puts("?");
    }
    return 0;
}
