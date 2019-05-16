#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int a,b;
    while (~scanf("%d %d", &a, &b)) {
        printf("%.10f\n", (double)a/b);
    }
    return 0;
}
