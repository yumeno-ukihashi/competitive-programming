#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,b,ans;
    map<pair<int,int>,bool> mp;
    while (~scanf("%d", &n)) {
        ans = 0;
        mp.clear();
        REP(i,1,n) {
            scanf("%d %d",&a,&b);
            if (a>b) swap(a,b);
            if (!mp[make_pair(a,b)]) {
                mp[make_pair(a,b)] = true;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
