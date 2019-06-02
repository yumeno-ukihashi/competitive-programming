#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
using namespace std;
int n,m,A[M],B[M];
bool check(int x) {
    int c=0;
    map<int,int> cnt;
    REP(i,1,n) if(A[i]!=x && B[i]!=x) {
        cnt[A[i]]++;
        cnt[B[i]]++;
        c++;
    }
    if (c==0) return true;
    for (auto i:cnt) if(i.second == c) return true;
    return false;
}
int main()
{
    while (~scanf("%d %d", &m,&n)) {
        REP(i,1,n) scanf("%d %d",&A[i],&B[i]);
        if (check(A[1]) || check(B[1])) puts("YES");
        else puts("NO");
    }
    return 0;
}
