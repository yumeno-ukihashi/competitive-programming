#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
typedef pair<int,int> P;
int n;
P in[2*M];
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) {
            int x,y;
            scanf("%d %d",&x,&y);
            in[i*2-1] = make_pair(x, -1);
            in[i*2] = make_pair(y, 1);
        }
        sort(in+1, in+2*n+1);

        int ans = 0;
        int dep = 0;
        REP(i,1,2*n) {
            if (dep==0 && in[i].second==-1) ans++;
            dep -= in[i].second;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}


