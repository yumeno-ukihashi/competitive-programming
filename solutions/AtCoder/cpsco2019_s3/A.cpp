#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

int main()
{
    char in[100];
    scanf("%s", in);
    int n = strlen(in);
    REP(i,0,n-1) {
        if (in[i]=='O') putchar('A');
        else if (in[i]=='A') putchar('O');
        else putchar(in[i]);
    }
    puts("");
    
    return 0;
}

