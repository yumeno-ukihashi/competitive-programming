#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;

int n,m,q,sx,sy;
char s[M], t[M];

char inv(char x) {
    if (x=='U') return 'D';
    if (x=='D') return 'U';
    if (x=='L') return 'R';
    if (x=='R') return 'L';
    return 0;
}
bool check(char mx,char my) {
    int x = sx;
    int y = sy;
    REP(i,1,q) {
        if (s[i]==mx) {
            x += mx=='U' ? -1 : 1;
        }
        if (s[i]==my) {
            y += my=='L' ? -1 : 1;
        }
        if (x<=0 || x>n || y<=0 || y>m) return true;

        if (t[i]==inv(mx)) {
            x += inv(mx)=='U' ? -1 : 1;
            if (x<=0 || x>n) x -= inv(mx)=='U' ? -1 : 1;
        }
        if (t[i]==inv(my)) {
            y += inv(my)=='L' ? -1 : 1;
            if (y<=0 || y>m) y -= inv(my)=='L' ? -1 : 1;
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d %d %d",&n,&m,&q)) {
        scanf("%d %d",&sx,&sy);
        scanf("%s", s+1);
        scanf("%s", t+1);

        if (check('U', 'L') || check('U', 'R') || check('D', 'L') || check('D', 'R')) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    
    return 0;
}




