#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int f(int x) {
    return x%2==0 ? x/2 : 3*x+1;
}
int main()
{
    int s;
    while (~scanf("%d", &s)) {
        
        int ans=0, n=1, cur=s;
        map<int,int> vis;
        vis[s] = 1;
        while (1) {
            cur = f(cur);
            n++;
            if (!vis[cur]) {
                vis[cur] = n;
            } else {
                ans = n;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
