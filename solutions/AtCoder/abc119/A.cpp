#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int y,m,d;
    while (~scanf("%d/%d/%d", &y,&m,&d)) {
        if (y<=2018 || y<=2019&&m<=4) {
            puts("Heisei");
        } else {
            puts("TBD");
        }
    }
    
    return 0;
}


