#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int a,b,c;
    while (~scanf("%d %d %d", &a,&b,&c)) {
        int cur = 0;
        REP(i,1,1000005) {
            cur += a;
            if (i%7==0) cur += b;
            if (cur >= c) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
