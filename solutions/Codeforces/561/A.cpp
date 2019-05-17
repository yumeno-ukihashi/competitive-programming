#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int n;
int cnt[26];
int main()
{
    char tmp[30];
    while (~scanf("%d", &n)) {
        MSET(cnt, 0);
        REP(i,1,n) {
            scanf("%s", tmp);
            cnt[tmp[0]-'a']++;
        }

        int ans = 0;
        REP(i,0,25) {
            int x = cnt[i]/2;
            int y = cnt[i]-x;
            ans += x*(x-1)/2 + y*(y-1)/2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
