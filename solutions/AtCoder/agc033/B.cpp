#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;

int n,m,q,sx,sy;
char s[M], t[M];

int main()
{
    while (~scanf("%d %d %d",&n,&m,&q)) {
        scanf("%d %d",&sx,&sy);
        scanf("%s", s+1);
        scanf("%s", t+1);

        bool fail = false;
        int x1=1, x2=n;
        int y1=1, y2=m;
        for (int i=q; i>=1; i--) {
            if (t[i]=='U') x2 = min(n, x2+1);
            if (t[i]=='D') x1 = max(1, x1-1);
            if (t[i]=='L') y2 = min(m, y2+1);
            if (t[i]=='R') y1 = max(1, y1-1);

            if (s[i]=='U') x1++;
            if (s[i]=='D') x2--;
            if (s[i]=='L') y1++;
            if (s[i]=='R') y2--;
            if (x1>x2 || y1>y2) fail = true;
        }
        puts(x1<=sx && sx<=x2 && y1<=sy && sy<=y2 && !fail ? "YES" : "NO");
    }
    
    return 0;
}

