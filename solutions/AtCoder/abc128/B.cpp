#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    vector<tuple<string,int,int>> vec;
    while (~scanf("%d", &n)) {
        vec.clear();
        REP(i,1,n) {
            string x;
            int y;
            cin >> x >> y;
            vec.push_back( make_tuple(x, -y, i) );
        }
        sort(vec.begin(), vec.end());
        for (auto i:vec) {
            string x;
            int y,z;
            tie(x,y,z) = i;
            printf("%d\n", z);
        }
    }
    return 0;
}
