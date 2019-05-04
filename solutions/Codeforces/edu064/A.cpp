#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,in[105];
int main()
{
  while (~scanf("%d", &n)) {
    int ans = 0;
    REP(i,1,n) scanf("%d", &in[i]);
    REP(i,2,n) {
      if (in[i]+in[i-1]>=5) {
        ans += 1000;
      } else if (in[i]+in[i-1]==3) {
        ans += 3;
        if (in[i]==2 && i-2>=1 && in[i-2]==3) ans--;
      } else if (in[i]+in[i-1]==4) {
        ans += 4;
      }
    }

    if (ans<1000) {
      puts("Finite");
      printf("%d\n", ans);  
    } else {
      puts("Infinite");
    }
  }
  return 0;
}

