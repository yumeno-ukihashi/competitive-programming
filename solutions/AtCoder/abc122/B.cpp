#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
bool chk(char x) {
    return x=='A' || x=='T' || x=='G' || x=='C';
}
int main()
{
    char in[200];
    while (~scanf("%s", in+1)) {
        int n = strlen(in+1);
        int ans = 0;
        REP(i,1,n) if(chk(in[i])) {
            int j = i;
            while (j+1<=n && chk(in[j+1])) j++;
            ans = max(ans, j-i+1);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}


