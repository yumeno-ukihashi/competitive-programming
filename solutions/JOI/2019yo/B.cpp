#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int n,m,in[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d",&in[i]);
        scanf("%d", &m);
        REP(i,1,m) {
            int x;
            scanf("%d",&x);
            if (x<n && in[x]+1<in[x+1]) {
                in[x]++;
            }
            if (x==n && in[x]+1<=2019) {
                in[x]++;
            }
        }
        REP(i,1,n) printf("%d\n", in[i]);
    }
    return 0;
}
