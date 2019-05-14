#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int a,b,k;
    while (~scanf("%d %d %d",&a,&b,&k)) {
        int ans = 0;
        int cnt=0;
        for (int i=min(a,b); i>=1; i--) {
            if (a%i==0 && b%i==0) {
                cnt++;
                if (cnt==k) {
                    ans = i;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}

