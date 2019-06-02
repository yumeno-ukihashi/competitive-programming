#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using P = pair<int,int>;
using T = tuple<int,int,int>;
int n,q,dd[M],ans[M];
T in[M];
void init() {
    int s,t,x;
    REP(i,1,n) {
        scanf("%d %d %d",&s,&t,&x);
        in[i] = make_tuple(s-x, t-x-1, x);
    }
    sort(in+1, in+n+1);

    REP(i,1,q) scanf("%d", &dd[i]);
}
int main()
{
    while (~scanf("%d %d", &n,&q)) {
        init();

        int d,pos = 1;
        int l,r,x;
        multiset<P> valid;
        multiset<int> xs;
        for (int i=1; i<=q; i++) {
            d = dd[i];
            while (pos<=n) {
                tie(l,r,x) = in[pos];
                if (l>d) break;
                valid.insert( P(r,x) );
                xs.insert( x );
                pos++;
            }
            while (valid.size() && (*valid.begin()).first<d) {
                auto p = *valid.begin();
                valid.erase( valid.find(p) );
                xs.erase( xs.find(p.second) );
            }

            if (!xs.size()) ans[i] = -1;
            else ans[i] = *xs.begin();
        }
        REP(i,1,q) printf("%d\n", ans[i]);
    }
    return 0;
}

