#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    int n;
    char in[105];
    while (~scanf("%d", &n)) {
        scanf("%s", in+1);

        int cur=0;
        REP(i,1,n) {
            if (cur>0 && in[i]=='-') cur--;
            else if (in[i]=='+') cur++;
        }
        printf("%d\n", cur);
    }
    return 0;
}

