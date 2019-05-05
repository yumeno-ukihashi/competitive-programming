#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
using namespace std;
int n,in[M];
char c[M];
int main()
{
    char buf[3];
    while (~scanf("%d",&n)) {
        REP(i,1,n) {
            scanf("%s %d",buf,&in[i]);
            c[i] = buf[0];
        }

        int ans = 0;
        REP(i,1,n) if(c[i]=='+') ans += in[i];
        REP(i,1,n) if(c[i]=='*' && in[i]>0) ans *= in[i];
        printf("%d\n", ans);
    }
    return 0;
}


