#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    long long n;
    while (~scanf("%lld", &n)) {
        long long ans = 0;
        long long i=1, j=0, r, d;
        while (i<=n) {
            r = n/i;
            j = n/r;
            if (i!=j) {
                d = ((n%i) - (n%j)) / (j-i);
                if (n%i%d == r%d) {
                    ans += i + (n%i - r)/d;
                }
            } else if (i==j && r==n%i) {
                ans += i;
            }
            i = j+1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

