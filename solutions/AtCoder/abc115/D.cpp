#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
LL lv[51],pate[51];
LL calc(int n,LL x) {
    if (x==0) return 0;
    if (x==lv[n]) return pate[n];

    LL res = 0;
    if (x>=1+lv[n-1]+1) {
        res += 1 + calc(n-1, x-1-lv[n-1]-1);
    }
    if (x>=1) {
        res += calc(n-1, min(lv[n-1], x-1));
    }
    return res;
}
int main()
{
    lv[0] = 1;
    REP(i,1,50) lv[i] = 2*lv[i-1] + 3;
    pate[0] = 1;
    REP(i,1,50) pate[i] = 2*pate[i-1] + 1;

    int n;
    LL x;
    while (~scanf("%d %lld", &n, &x)) {
        printf("%lld\n", calc(n,x));
    }
    return 0;
}
