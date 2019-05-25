#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
bool check(int yr,int mo) {
    return mo>=1 && mo<=12;
}
int main()
{
    int n;
    int x,y;
    while (~scanf("%d", &n)) {
        x = n/100;
        y = n%100;

        if (check(x,y) && check(y,x)) puts("AMBIGUOUS");
        else if (check(x,y)) puts("YYMM");
        else if (check(y,x)) puts("MMYY");
        else puts("NA");
    }
    return 0;
}
