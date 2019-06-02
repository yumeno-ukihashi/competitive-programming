#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int a,p;
    while (~scanf("%d %d", &a,&p)) {
        printf("%d\n", (3*a+p)/2);
    }
    return 0;
}
