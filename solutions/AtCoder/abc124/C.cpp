#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n;
char in[M];
int main()
{ 
    while (~scanf("%s",in+1)) {
        n = strlen(in+1);

        int ans = 1000000000;
        REP(x,0,1) {
            int cnt = 0;
            REP(i,1,n) {
                cnt += (in[i]-48) ^ (i%2) ^ x;
            }
            ans = min(ans, cnt);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

