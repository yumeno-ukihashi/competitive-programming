#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 520
using namespace std;
int n,m,ar[M];
void gen1D() {
    int bits = 1;
    m = 2;
    while (m<n) { m *= 2; bits++; }
    REP(i,0,m-1) {
        int x = i;
        ar[i] = 0;
        REP(j,0,bits-1) if ((1<<j)&x) ar[i] |= 1<<(bits-j-1);
    }
    
    int pos=0;
    REP(i,0,m-1) {
        if (ar[i]<n) ar[pos++] = ar[i];
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        gen1D();
        REP(i,0,n-1) {
            REP(j,0,n-1) printf("%d%c", n*ar[i]+ar[j]+1, j==n-1 ? '\n' : ' ');
        }
    }
    
    return 0;
}

