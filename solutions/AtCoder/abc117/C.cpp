#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m,in[M];
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        REP(i,1,m) scanf("%d", &in[i]);
        sort(in+1, in+m+1);

        REP(i,1,m-1) in[i] = in[i+1]-in[i];
        sort(in+1, in+m);

        if (n>=m) {
            puts("0");
        } else {
            printf("%lld\n", accumulate(in+1, in+m-n+1, 0LL));
        }
    }
    return 0;
}
