#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
using P = pair<int,int>;
int n;
char in[M];
bool vis[M];
vector<P> segs;

int main()
{
    while (~scanf("%d%s",&n,in+1)) {
        MSET(vis, false);
        segs.clear();

        REP(i,3,n) if (in[i]=='B' && in[i-1]=='G' && in[i-2]=='R') {
            vis[i-2] = vis[i-1] = vis[i] = true;
            segs.push_back( make_pair(i-2, i) );
        }

        REP(i,0,(int)segs.size()-1) {
            int l = segs[i].first;
            int r = segs[i].second;
            int lb = (i==0 ? 1 : segs[i-1].second+1);
            int rb = (i==(int)segs.size()-1 ? n : segs[i+1].first-1);

            while (1) {
                if (l-3>=lb && in[l-3]=='R' && in[l-2]=='G' && in[l-1]=='B') l-=3;
                else if (l-2>=lb && in[l-2]=='R' && in[l-1]=='G') l -= 2;
                else if (l-1>=lb && in[l-1]=='R') l -= 1;
                else break;
            }

            while (1) {
                if (r+3<=rb && in[r+1]=='R' && in[r+2]=='G' && in[r+3]=='B') r+=3;
                else if (r+2<=rb && in[r+1]=='G' && in[r+2]=='B') r+=2;
                else if (r+1<=rb && in[r+1]=='B') r++;
                else break;
            }

            REP(j,l,r) vis[j] = true;
        }

        REP(i,1,n) if(!vis[i]) {
            int j = i;
            while (j+1<=n && !vis[j+1]) j++;
            if (i!=1 && j!=n && i==j && in[i]=='G' && i-1>=1 && i+1<=n) {
                vis[i] = true;
            }
            i = j;
        }

        bool fail = false;
        REP(i,1,n) if(!vis[i]) fail = true;
        puts(fail ? "No":"Yes");
    }
    return 0;
}



// RGB R RGB
//
//
//
// RGBBB GGGGGG RRGB
//
// RGBBB G RRGB
//


