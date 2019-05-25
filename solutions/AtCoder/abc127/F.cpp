#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
int main()
{
    int n,q,a,b,c;
    LL ss1, ss2, cons;
    multiset<int> s1,s2;
    while (~scanf("%d", &q)) {
        n = 0;
        s1.clear();
        s2.clear();
        ss1 = 0;
        ss2 = 0;
        cons = 0;

        
        while (q--) {
            scanf("%d",&c);
            if (c==1) {
                n++;
                scanf("%d %d",&a,&b);
                cons += b;

                if ((int)s1.size()==0 || a<=*s1.rbegin()) {
                    s1.insert(a);
                    ss1 += a;
                } else {
                    s2.insert(a);
                    ss2 += a;
                }

                int small = (n+1)/2;
                int big = n - small;
                int tmp = 0;
                while ((int)s1.size() > small) {
                    tmp = *s1.rbegin();
                    s1.erase(s1.find(tmp));
                    ss1 -= tmp;
                    s2.insert(tmp);
                    ss2 += tmp;
                }
                while ((int)s2.size() > big) {
                    tmp = *s2.begin();
                    s2.erase(s2.find(tmp));
                    ss2 -= tmp;
                    s1.insert(tmp);
                    ss1 += tmp;
                }
            }
            if (c==2) {
                int small = (n+1)/2;
                int big = n-small;
                int a1 = *s1.rbegin();
                LL ans = (LL)small*a1 - ss1;
                ans += ss2 - (LL)big*a1;
                printf("%d %lld\n",a1, ans + cons);
            }
        }
    }
    return 0;
}
