#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 50005
using namespace std;
int n,A[M],B[M];
int main()
{
    while (~scanf("%d", &n)) {
        auto check = [&](int x) {
            REP(i,1,n) if(A[i]%x!=0 && B[i]%x!=0) return false;
            return true;
        };
        auto facs = [](int x) {
            vector<int> res;
            int sq = (int)sqrt(x);
            REP(i,1,sq) {
                if (x%i==0) res.push_back(i);
                if (i!=x/i) res.push_back(x/i);
            }
            return res;
        };
        REP(i,1,n) scanf("%d %d", &A[i], &B[i]);

        int ans = 0;
        for (auto i:facs(A[1])) if (check(i)) ans = max(ans, i);
        for (auto i:facs(B[1])) if (check(i)) ans = max(ans, i);
        printf("%d\n", ans);

    }
    return 0;
}
