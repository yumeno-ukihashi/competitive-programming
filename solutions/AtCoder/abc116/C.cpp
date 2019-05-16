#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int n,in[M];
int work() {
    REP(i,1,n) if (in[i]!=0) {
        int j = i;
        while (j+1<=n && in[j+1]!=0) j++;

        int res = *min_element(in+i, in+j+1);
        REP(k,i,j) in[k] -= res;
        return res;
    }
    return 0;
}
int main()
{
    while (~scanf("%d", &n)) {
        int ans = 0;
        REP(i,1,n) scanf("%d", &in[i]);
        while (1) {
            int x = work();
            if (!x) break;
            ans += x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
