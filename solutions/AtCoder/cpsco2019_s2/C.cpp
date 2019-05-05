#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m;
char in[M];
vector<int> num;
int main()
{
    while (~scanf("%d %d",&n,&m)) {
        num.clear();
        scanf("%s", in+1);

        int dep = 0;
        num.push_back(0);
        REP(i,1,n) {
            dep += in[i]=='(' ? 1 : -1;
            num.push_back(dep);
        }
        sort(num.begin(), num.end(), greater<int> ());

        long long ans = 0;
        REP(i,0,m-1) ans += num[i];
        printf("%lld\n", ans);
    }
    return 0;
}



