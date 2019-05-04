#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    int n,a;
    while (~scanf("%d %d",&n,&a)) {
        printf("%d %d\n", (a+2)/3, min(n/3,a));
    }
    return 0;
}


