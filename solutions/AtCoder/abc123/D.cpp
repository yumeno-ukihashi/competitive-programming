#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
using namespace std;
using LL = long long;
int X, Y, Z, K;
LL A[M], B[M], C[M];
bool check(LL x) {
    LL cnt = 0;
    REP(i,1,X) {
        int k = Z+1;
        REP(j,1,Y) {
            while (k-1>=1 && A[i]+B[j]+C[k-1]>=x) k--;
            cnt += Z+1 - k;
        }
    }
    return cnt >= K;
}
vector<LL> out_greater(LL x) {
    vector<LL> res;
    REP(i,1,X) {
        int k = Z+1;
        REP(j,1,Y) {
            while (k-1>=1 && A[i]+B[j]+C[k-1]>x) k--;
            REP(k2, k, Z) res.push_back(A[i]+B[j]+C[k2]);
        }
    }
    return res;
}
int main()
{
    while (~scanf("%d %d %d %d",&X,&Y,&Z,&K)) {
        REP(i,1,X) scanf("%lld", &A[i]);
        REP(i,1,Y) scanf("%lld", &B[i]);
        REP(i,1,Z) scanf("%lld", &C[i]);
        sort(A+1, A+X+1);
        sort(B+1, B+Y+1);
        sort(C+1, C+Z+1);

        LL ok=0, ng=10000000000LL*3 + 1, mid;
        while (abs(ok-ng) > 1) {
            mid = (ok+ng) / 2;
            if (check(mid)) ok = mid;
            else ng = mid;
        }
        //printf("ok = %lld\n", ok);

        vector<LL> ans = out_greater(ok);
        sort(ans.begin(), ans.end(), greater<LL> ());
        while ((int)ans.size() < K) ans.push_back(ok);
        for (auto i: ans) printf("%lld\n", i);
    }
    
    return 0;
}

