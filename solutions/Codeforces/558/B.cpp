#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m,in[M];
int cnt[M];
int main()
{
    while (~scanf("%d",&n)) {
        m = 0;
        multiset<int> s;
        MSET(cnt, 0);
        REP(i,1,n) scanf("%d",&in[i]);

        REP(i,1,n) if(cnt[in[i]]==0) {
            cnt[in[i]]++;
            m++;
        }

        int ans = 0;
        MSET(cnt,0);
        REP(i,1,n) {
            if (cnt[in[i]]) s.erase(s.find(cnt[in[i]]));
            cnt[in[i]]++;
            s.insert(cnt[in[i]]);

            auto check = [&]() {
                //if ((int)s.size() != m) return false;
                if ((int)s.size() == 1) return true;
                auto i1 = s.begin();
                auto i2 = i1; i2++;
                auto i3 = s.end(); i3--;
                auto i4 = i3; i4--;

                
                return ((*i1)==(*i4) && (*i3)==(*i1)+1) || (*i1==1 && *i2==*i3);
            };
            if (check()) {
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}




