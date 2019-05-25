#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int ans[1<<20];
int main()
{
    int n,m,k;

    while (~scanf("%d %d", &m, &k)) {
        n = (1<<m);
        if (k>n-1 || (m==1 && k==1)) {
            puts("-1");
            continue;
        }

        if (k==0) {
            REP(i,0,2*n-1) ans[i] = i/2;
        } else {
            ans[0] = 0;
            ans[1] = k;
            ans[2] = 0;
            
            int pos=3;
            REP(i,0,n-1) if(i!=0 && i!=k) ans[pos++] = i;
            ans[pos++] = k;
            for (int i=n-1; i>=0; i--) if(i!=0 && i!=k) ans[pos++] = i;
        }

        REP(i,0,2*n-1) printf("%d%c", ans[i], i==2*n-1 ? '\n' : ' ');
    }
    return 0;
}
