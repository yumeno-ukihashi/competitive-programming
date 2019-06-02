#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    char in[200];
    while (~scanf("%s", in+1)) {
        n = strlen(in+1);
        int cnt=15-n;
        REP(i,1,n) if(in[i]=='o') cnt++;
        puts(cnt>=8 ? "YES" : "NO");
    }
    return 0;
}
