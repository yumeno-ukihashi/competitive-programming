#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,in1[M],in2[M],t[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in1[i]);
        REP(i,1,n) scanf("%d", &in2[i]);
        REP(i,1,n) if(in1[i]) t[in1[i]] = 0;
        REP(i,1,n) if(in2[i]) t[in2[i]] = i;

        int ans = 0;
        REP(i,1,n) ans = max(ans, t[i]+n-i+1);

        if (t[1]) {
            bool flag = true;
            REP(i,t[1],n) if(in2[i] != i-t[1]+1) flag = false;
            if (flag) {
                bool flag2 = true;
                REP(i,in2[n]+1,n) if (t[i] > i-in2[n]-1) flag2 = false;
                if (flag2) ans = min(ans, t[1]-1);
            }
        }


        printf("%d\n", ans);
    }
    return 0;
}
