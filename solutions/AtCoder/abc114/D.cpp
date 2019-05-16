#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int cnt[105][105]; //cnt[n!][prime]
void init() {
    vector<bool> isp(101, true);
    isp[0] = isp[1] = false;
    REP(i,2,100) if(isp[i]) for (int j=2*i; j<=100; j+=i) isp[j] = false;

    MSET(cnt, 0);
    REP(i,1,100) {
        REP(j,1,100) cnt[i][j] = cnt[i-1][j];
        REP(j,1,100) if(isp[j]) {
            int x=i, c=0;
            while (x%j==0) x/=j, c++;
            cnt[i][j] += c;
        }
    }
}
int main()
{
    init();
    
    int n;
    while (~scanf("%d", &n)) {
        int ans=0;
        REP(i,1,n) if(cnt[n][i]>=74) ans++;
        REP(i,1,n)REP(j,1,n) if (i!=j) {
            if (cnt[n][i]>=2 && cnt[n][j]>=24) ans++;
            if (cnt[n][i]>=4 && cnt[n][j]>=14) ans++;
        }
        REP(i,1,n)REP(j,1,n)REP(k,j+1,n) if(i!=j && j!=k && i!=k) {
            if (cnt[n][i]>=2 && cnt[n][j]>=4 && cnt[n][k]>=4) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
