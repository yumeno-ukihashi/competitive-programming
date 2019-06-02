#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,in[55];
    while (~scanf("%d", &n)) {
        REP(i,1,n) scanf("%d", &in[i]);
        sort(in+1, in+n+1);
        if (in[1]==in[n/2+1]) puts("Bob");
        else puts("Alice");
    }
    return 0;
}
