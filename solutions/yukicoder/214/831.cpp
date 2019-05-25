#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n)) {
        
        __int128 ans = 0;
        if (n==1) {
            puts("0");
            continue;
        } else {
            __int128 nn = n;
            if (n % 2) {
                ans = (nn*nn*nn + 3*nn*nn + 5*nn - 3)/6;
            } else {
                ans = (nn*nn*nn + 3*nn*nn + 5*nn - 6)/6;
            }
        }

        printf("%lld\n", (long long)ans);
    }
    return 0;
}
