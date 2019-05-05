#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int n,p[100];
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) p[i] = i;

        map<int,int> mp;
        do {
            int s=0, b=0;
            REP(i,1,n) {
                if (i<p[i]) s++;
                if (i>p[i]) b++;
            }

            if (s+b==n) mp[s]++;
        } while (next_permutation(p+1, p+n+1));

        for (auto i:mp) printf("%d %d\n",i.first,i.second);
    }
    return 0;
}


