#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
int main()
{
    int n;
    char tmp[20];
    while (~scanf("%d", &n)) {
        double sum = 0.0;
        REP(i,1,n) {
            double x;
            scanf("%lf %s",&x,tmp);
            if (tmp[0]=='J') sum += x;
            else sum += x * 380000;
        }
        printf("%.10f\n", sum);
    }
    
    return 0;
}

