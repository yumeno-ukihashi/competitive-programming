#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    int n,m;
    while (~scanf("%d %d",&m,&n)) {
        printf("%d\n", m/n + m%n);
    }
    
    return 0;
}

