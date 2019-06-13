#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int p,q,r;
    while (~scanf("%d %d %d", &p, &q, &r)) {
        printf("%d\n", p+q+r-max(p,max(q,r)));
    }
    return 0;
}
