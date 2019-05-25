#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using P = pair<int,int>;
int n,ord[M];
P in[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d %d",&in[i].first, &in[i].second);

        bool flag = true;
        int mxid = -1;
        REP(i,1,n) {
            if (mxid==-1 || (long long)in[mxid].first*in[mxid].second < (long long)in[i].first*in[i].second)
                mxid = i;
        }
        REP(i,1,n) if(i!=mxid) {
            int ti = (in[i].first+in[mxid].second-1)/in[mxid].second;
            int ta = (in[mxid].first+in[i].second-1)/in[i].second;
            if (ti>=ta) flag = false;
        }

        printf("%d\n", flag ? mxid : -1);
        
    }
    return 0;
}
