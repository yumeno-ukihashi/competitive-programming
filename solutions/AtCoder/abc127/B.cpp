#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int r,d,x;
    while (~scanf("%d %d %d", &r,&d,&x)) {
        REP(i,1,10) {
            x = r*x-d;
            printf("%d\n", x);
        }
    }
    return 0;
}
