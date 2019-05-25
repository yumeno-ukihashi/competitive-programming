#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,k;
    char in[505];
    while (~scanf("%d %d", &n,&k)) {
        scanf("%s", in+1);
        REP(i,1,n) {
            if (i==k) putchar(in[i]+32);
            else putchar(in[i]);
        }
        puts("");
    }
    return 0;
}
