#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 105
using namespace std;
int t,n,cnt[26];
char in[M];
int main()
{
  scanf("%d",&t);
  while(t--) {
    MSET(cnt, 0);
    scanf("%s", in);
    n = strlen(in);
    REP(i,0,n-1) {
      cnt[in[i]-'a']++;
    }

    vector<int> nums;
    REP(i,0,25) if (cnt[i]) {
      nums.push_back(i);
    }
    int m = nums.size();
    
    if (m==2 && nums[0]==nums[1]-1) {
      puts("No answer");
    } else if (m==3 && nums[2]-nums[0]==2) {
      puts("No answer");
    } else if (m==3 && nums[1]-nums[0]==1) { //abd
      for (int i=1; i<m; i+=2) REP(j,1,cnt[nums[i]]) putchar('a' + nums[i]);
      for (int i=2; i>=0; i-=2) REP(j,1,cnt[nums[i]]) putchar('a' + nums[i]);
      puts("");
    } else {
      for (int i=1; i<m; i+=2) REP(j,1,cnt[nums[i]]) putchar('a' + nums[i]);
      for (int i=0; i<m; i+=2) REP(j,1,cnt[nums[i]]) putchar('a' + nums[i]);
      puts("");
    }
  }
  return 0;
}
