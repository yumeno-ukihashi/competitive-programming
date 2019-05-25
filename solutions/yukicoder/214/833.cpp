#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using LL = long long;
using P = pair<int,int>;
int n,q;
LL tree[M];
int low(int x) { return x&-x; }
void add(int x,int v) {
    for (int i=x; i<=n; i+=low(i))
        tree[i] += v;
}
LL ask(int x) {
    LL res = 0;
    for (int i=x; i>0; i-=low(i))
        res += tree[i];
    return res;
}
LL ask(int x,int y) {
    return ask(y) - ask(x-1);
}
int main()
{
    set<P> s;
    while (~scanf("%d %d", &n, &q)) {
        s.clear();
        MSET(tree, 0);
        REP(i,1,n) {
            int x;
            scanf("%d", &x);
            add(i, x);
        }
        REP(i,1,n) s.insert( make_pair(i,i) );

        auto find_seg = [&](int x) {
            auto it = s.upper_bound( make_pair(x+1, -1) );
            if (it==s.begin()) return make_pair(-1, -1);
            --it;
            return *it;
        };

        REP(i,1,q) {
            int x,y;
            scanf("%d %d",&x,&y);
            if (x==1) {
                auto seg = find_seg(y);
                auto seg2 = find_seg(y+1);
                if (seg!=seg2) {
                    s.erase(seg);
                    s.erase(seg2);
                    s.insert(make_pair(seg.first, seg2.second));
                }
            }
            if (x==2) {
                auto seg = find_seg(y);
                if (y+1 <= seg.second) {
                    s.erase(seg);
                    s.insert(make_pair(seg.first, y));
                    s.insert(make_pair(y+1, seg.second));
                }
            }
            if (x==3) {
                add(y, 1);
            }
            if (x==4) {
                auto seg = find_seg(y);
                printf("%lld\n", ask(seg.first, seg.second));
            }
        }
    }
    return 0;
}
