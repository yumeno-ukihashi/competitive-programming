#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int in[5], n;
    REP(i,0,4) scanf("%d",&in[i]);
    sort(in, in+5);
    scanf("%d",&n);
    puts(in[4]-in[0] <= n ? "Yay!" : ":(");
    
    return 0;
}

