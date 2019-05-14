#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
LL prefix(LL n) {
    n++;
    
    LL ans = 0;
    REP(bit, 0, 40) {
        int res = 0;
        LL gumi = n / (1LL << (bit+1));
        if (bit==0 && gumi%2==1) res = 1;
        LL tmp = n - (1LL << (bit+1))*gumi - (1LL << (bit));
        if (tmp>0 && tmp%2==1) res ^= 1;

        ans |= (1LL << bit) * res;
    }
    return ans;
}
int main()
{
    LL A,B;
    while (~scanf("%lld %lld",&A,&B)) {
        printf("%lld\n", prefix(B) ^ prefix(A-1));
    }
    
    return 0;
}

