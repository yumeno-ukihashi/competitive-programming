#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
int n,m;
bool ans;
map<P,bool> mp;
int main()
{
    while (~scanf("%d %d", &n, &m)) {
        ans = false;
        mp.clear();
        REP(i,1,m) {
            int x,y;
            scanf("%d %d",&x,&y);
            if (x>y) swap(x,y);
            mp[make_pair(x,y)] = true;
        }

        auto check = [](int x) {
            for (auto ii:mp) if (ii.second) {
                auto i = ii.first;
                auto j = make_pair((i.first+x)%n, (i.second+x)%n);
                if (j.first==0) j.first = n;
                if (j.second==0) j.second = n;
                if (j.first > j.second) swap(j.first, j.second);
                if (!mp[j]) return false;
            }
            return true;
        };

        int sq = (int)sqrt(n);
        REP(i,1,sq) if(n%i==0) {
            if (check(i)) ans = true;
            if (i!=1 && check(n/i)) ans = true;
            if (ans) break;
        }
        puts(ans ? "Yes" : "No");
    }
    return 0;
}
