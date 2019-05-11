#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 10005
using namespace std;
int n;
string in[M];
int main()
{
    
    while (~scanf("%d",&n)) {
        int ans = 0;
        REP(i,1,n) cin >> in[i];
        REP(i,1,n) REP(j,1,(int)in[i].length()-1) {
            if (in[i][j-1]=='A' && in[i][j]=='B')
                ans++;
        }

        int a=0, b=0, ab=0;
        REP(i,1,n) {
            if (in[i][0]=='B' && in[i].back()=='A') {
                ab++;
            } else if (in[i][0]=='B') {
                a++;
            } else if (in[i].back() == 'A') {
                b++;
            }
        }

        if (ab) {
            ans += ab-1;
            ab = 1;
        }
        if (ab) {
            if (b && a) {
                ans += 2;
                ab--;
                b--;
                a--;    
            } else if (b) {
                ab--;
                ans++;
            } else if (a) {
                ab--;
                ans++;
            }
        }
        ans += min(a,b);
        printf("%d\n", ans);
    }
    return 0;
}

