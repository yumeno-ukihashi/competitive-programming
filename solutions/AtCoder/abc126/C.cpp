#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n,k;
    long double ans;
    vector<long double> lds;
    while (~scanf("%d %d", &n,&k)) {
        lds.clear();
        ans = 0.0;
        REP(i,1,n) {
            int x=i, cnt=0;
            while (x<k) {
                cnt++;
                x *= 2;
            }

            lds.push_back ( pow(0.5, cnt) );
        }
        sort(lds.begin(), lds.end());

        for (auto i:lds) ans += i;

        printf("%.15f\n", (double)(ans/n));
    }
    return 0;
}
