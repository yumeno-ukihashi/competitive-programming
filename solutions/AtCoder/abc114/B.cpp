#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 15
using namespace std;
using LL = long long;
int n;
char in[M];
LL getnum(int x,int y) {
    LL re = 0;
    REP(i,x,y) {
        re = re*10 + in[i]-48;
    }
    return re;
}
int main()
{
    while (~scanf("%s", in+1)) {
        LL ans = 77777777;
        n = strlen(in+1);
        REP(i,3,n) {
            LL x = getnum(i-3+1,i);
            ans = min(ans, abs(753-x));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
