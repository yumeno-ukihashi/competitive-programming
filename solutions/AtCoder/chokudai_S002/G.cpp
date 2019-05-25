#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b;
    while (~scanf("%d", &n)) {
        REP(i,1,n) {
            scanf("%d %d",&a,&b);
            printf("%d\n", __gcd(a,b));
        }
    }
    return 0;
}
