#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    char in[200];
    while (~scanf("%s", in+1)) {
        int n = strlen(in+1);
        REP(i,1,n) {
            if (in[i]=='A') putchar('T');
            if (in[i]=='T') putchar('A');
            if (in[i]=='C') putchar('G');
            if (in[i]=='G') putchar('C');
        }
        puts("");
    }
    
    return 0;
}

