#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
int n,m,k;
P ord[M];
char in[M];
int main()
{
    while (~scanf("%d %d",&n,&k)) {
        m = 0;
        scanf("%s", in+1);
        REP(i,1,n) {
            int j=i;
            while (j+1<=n && in[j+1]==in[j]) j++;
            ord[++m] = make_pair(in[i]-48, j-i+1);
            i = j;
        }

        int r=0, c0=0, sum=0, ans=0;
        int l=1;
        while (l<=m) {
            r = max(l-1, r);
            while (r+1<=m && c0+(ord[r+1].first==0 ? 1 : 0)<=k) {
                sum += ord[r+1].second;
                c0 += (ord[r+1].first == 0 ? 1 : 0);
                r++;
            }

            ans = max(ans, sum);

            sum -= ord[l].second;
            c0 -= (ord[l].first == 0 ? 1 : 0);
            l++;
        }
        printf("%d\n", ans);

    }
    
    return 0;
}

