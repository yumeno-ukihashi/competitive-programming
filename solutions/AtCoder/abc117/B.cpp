#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 15
using namespace std;
int n,in[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        sort(in+1, in+n+1);
        if (accumulate(in+1, in+n, 0) > in[n]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
