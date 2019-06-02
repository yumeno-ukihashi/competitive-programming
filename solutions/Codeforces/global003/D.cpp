#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using T = tuple<int,int,int>;

int n;
vector<T> s,m;
int main()
{
    while (~scanf("%d", &n)) {
        s.clear();
        m.clear();
        REP(i,1,n) {
            int x,y;
            scanf("%d %d",&x,&y);
            if (x<y) s.push_back( T(x,y,i) );
            else m.push_back( T(x,y,i) );
        }

        sort(s.begin(), s.end(), greater<T>());
        sort(m.begin(), m.end());
        if (s.size() <= m.size()) swap(s,m);

        
        printf("%d\n", (int)s.size());
        REP(i,0,(int)s.size()-1) {
            int x,y,z;
            tie(x,y,z) = s[i];
            printf("%d%c",z,i==(int)s.size()-1 ? '\n' : ' ');
        }
    }
    return 0;
}
