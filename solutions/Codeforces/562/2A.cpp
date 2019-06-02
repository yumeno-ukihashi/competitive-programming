#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,a,x,b,y;
    while (~scanf("%d %d %d %d %d", &n,&a,&x,&b,&y)) {
        bool ans = false;

        REP(i,1,n+2) {
            if (a==b) ans = true;
            if (a==x || b==y) break;
            
            a++; if(a>n)a=1;
            b--; if(b<=0)b=n;
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
