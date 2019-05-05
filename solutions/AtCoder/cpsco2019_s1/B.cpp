#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;

int n,cnt[26];
char in[M];
char S[M], T[M];
int main()
{
    while (~scanf("%s",in+1)) {
        MSET(cnt, 0);
        n = strlen(in+1);
        REP(i,1,n) cnt[in[i]-'a']++;

        bool fail = false;
        int tmp = 0;
        REP(i,0,25) {
            if (!tmp && cnt[i]) tmp = cnt[i];
            else if (tmp && cnt[i] && cnt[i]!=tmp) fail = true;
        }
        puts(fail ? "No" : "Yes");
    }
    return 0;
}


