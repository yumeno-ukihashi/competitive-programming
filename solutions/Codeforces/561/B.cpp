#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n)) {
        int x=-1, y=-1;
        int sq = (int)sqrt(n);

        REP(i,1,sq) if(n%i==0 && i>=5 && n/i>=5) {
            x = i;
            y = n/i;
            break;
        }
        if (x == -1) puts("-1");
        else {
            char v[6] = "aeiou";
            REP(i,1,x)REP(j,1,y)
                putchar(v[(i+j)%5]);
            puts("");
        }
    }
    return 0;
}
