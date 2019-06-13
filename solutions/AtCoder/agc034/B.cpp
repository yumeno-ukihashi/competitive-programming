#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n;
char in[M];
int main()
{
    while (~scanf("%s", in+1)) {
        n = strlen(in+1);
        long long ans = 0;

        REP(i,1,n) if(in[i]=='A') {
            int j = i-1;

            vector<int> tmp, tsum;
            while (1) {
                if (j+1<=n && in[j+1]=='A') { j+=1; tmp.push_back(0); }
                else if (j+2<=n && in[j+1]=='B' && in[j+2]=='C') { j+=2; tmp.push_back(1); }
                else break;
            }
            if ((int)tmp.size()==0) continue;

            tsum = vector<int>(tmp.size()+1);
            for (int k=tmp.size()-1; k>=0; k--) tsum[k] = tsum[k+1] + tmp[k];

            REP(k,0,(int)tmp.size()-1) if(tmp[k]==0) {
                ans += tsum[k+1];
            }

            i = j;
            //in[j-1] = 'A';
        }
        printf("%lld\n",ans);
    }
    return 0;
}
