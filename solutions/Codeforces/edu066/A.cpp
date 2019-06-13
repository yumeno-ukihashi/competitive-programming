#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int t;
    long long n,k;

    scanf("%d",&t);
    while (t--) {
        cin >> n >> k;
        long long ans = 0;
        while (n) {
            if (n%k) {
                ans += n%k;
                n -= n%k;
            } else {
                n /= k;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
