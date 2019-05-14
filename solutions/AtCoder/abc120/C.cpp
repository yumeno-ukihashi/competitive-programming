#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n;
char in[M];
int main()
{
    while (~scanf("%s", in+1)) {
        n = strlen(in+1);

        int c0=0, c1=0;
        REP(i,1,n) {
            if (in[i]=='0') c0++;
            else c1++;
        }
        printf("%d\n", min(c0, c1)*2);
    }
    
    return 0;
}
