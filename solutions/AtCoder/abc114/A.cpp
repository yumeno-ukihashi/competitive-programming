#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n)) {
        puts(n==3 || n==5 || n==7 ? "YES" : "NO");
    }
    return 0;
}
