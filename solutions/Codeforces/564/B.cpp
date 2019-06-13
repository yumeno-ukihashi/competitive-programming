#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int n;
int main()
{
    while (~scanf("%d", &n)) {
        vector<pair<int,int>> ans;

        int a0 = 0;
        REP(i,1,n) {
            int x = (i-1)/2 + 1;
            int y = x + (i%2==0 ? 1 : 0);
            ans.push_back(make_pair(x,y));
            a0 = max(a0, x);
            a0 = max(a0, y);
        }

        printf("%d\n", a0);
        for (auto i: ans) printf("%d %d\n",i.first,i.second);
    }
    return 0;
}
