#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
#define INF ((1LL<<32)-1)
using namespace std;

int main()
{
    int n;
    char cmd[20];
    vector<int> s;

    while (~scanf("%d", &n)) {
        s.clear();

        bool over = false;
        int cnt=0;
        long long ans=0, mult=1;
        
        REP(i,1,n) {
            scanf("%s", cmd);
            if (!strcmp(cmd, "add")) {
                if (cnt) { over = true; }
                else ans += mult;
            } else if (!strcmp(cmd, "for")) {
                int x;
                scanf("%d", &x);
                if (!cnt && mult*x <= INF) {
                    s.push_back(x);
                    mult *= x;
                } else {
                    cnt++;
                }
            } else {
                if (cnt) cnt--;
                else {
                    mult /= s.back();
                    s.pop_back();
                }
            }
        }

        if (ans>INF) over = true;

        if (over) puts("OVERFLOW!!!");
        else cout << ans << endl;
    }
    return 0;
}
