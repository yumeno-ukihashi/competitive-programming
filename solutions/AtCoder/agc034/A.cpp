#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,A,B,C,D;
char in[M];
int main()
{
    while (~scanf("%d %d %d %d %d", &n,&A,&B,&C,&D)) {
        scanf("%s", in+1);

        auto chk = [&](int x,int y) {
            REP(i,x+1,y) if(in[i]=='#' && in[i-1]=='#') return false;
            return true;
        };
        auto chk2 = [&](int x,int y) {
            REP(i,x,y) if(in[i-1]!='#' && in[i]!='#' && in[i+1]!='#') return true;
            return false;
        };

        if (C<D && chk(A,C) && chk(B,D)) puts("Yes");
        else if (C>D && chk(A,C) && chk(B,D) && chk2(B,D)) puts("Yes");
        else puts("No");
    }
    return 0;
}
