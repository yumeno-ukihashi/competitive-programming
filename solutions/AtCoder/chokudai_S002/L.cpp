#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using P = pair<int,int>;
int n,s[M],top;
P in[M];
int main()
{
    while (~scanf("%d", &n)) {
        REP(i,1,n) {
            scanf("%d %d",&in[i].first,&in[i].second);
            if (in[i].first > in[i].second) swap(in[i].first, in[i].second);
        }
        sort(in+1, in+n+1, [](P a,P b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        top = 0;
        REP(i,1,n) {
            if (!top || in[i].second > s[top-1]) s[top++] = in[i].second;
            else *lower_bound(s, s+top, in[i].second) = in[i].second;
        }
        printf("%d\n", top);
    }
    return 0;
}
