#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
bool vis[20];
bool check(vector<int> ar,int d,int toizu) {
    if (d==0) {
        REP(i,0,13) {
            int j=i;
            while (j+1<=13 && ar[j+1]==ar[j]) j++;
            if (j-i+1>4) return false;
            i = j;
        }

        bool flg = true;
        for (int i=1; i<14; i+=2) 
            if (ar[i]!=ar[i-1])
                flg = false;
        for (int i=3; i<14; i+=2)
            if (ar[i-1]==ar[i-2])
                flg = false;
        if (flg) return true; //chitoizu
    }
    if (d==14) {
        return true;
    }

    int pos=-1, pos2, pos3;
    REP(i,0,13) if (!vis[i]) {
        pos = i;
        break;
    }
    if (pos==-1) return false;

    //123 456
    pos2=-1, pos3=-1;
    REP(i,pos+1, 13) if (!vis[i]) {
        if (ar[i]==ar[pos]+1) pos2=i;
        if (ar[i]==ar[pos]+2) pos3=i;
    }
    if (pos3!=-1 && pos2!=-1) {
        vis[pos] = vis[pos2] = vis[pos3] = true;
        if (check(ar, d+3, toizu)) return true;
        vis[pos] = vis[pos2] = vis[pos3] = false;
    }

    //111 222
    pos2=-1, pos3=-1;
    REP(i,pos+1, 13) if (!vis[i]) {
        if (ar[i]==ar[pos] && pos2==-1) pos2=i;
        else if (ar[i]==ar[pos] && pos3==-1) pos3=i;
    }
    if (pos3!=-1 && pos2!=-1) {
        vis[pos] = vis[pos2] = vis[pos3] = true;
        if (check(ar, d+3, toizu)) return true;
        vis[pos] = vis[pos2] = vis[pos3] = false;
    }

    //11
    pos2 = -1;
    REP(i,pos+1, 13) if (!vis[i]) {
        if (ar[i]==ar[pos] && pos2==-1) pos2=i;
    }
    if (pos2!=-1 && toizu==0) {
        vis[pos] = vis[pos2] = true;
        if (check(ar, d+2, toizu+1)) return true;
        vis[pos] = vis[pos2] = false;
    }
    return false;
}
int main()
{
    vector<int> in, tmp, ans;
    char buf[20];
    while (~scanf("%s", buf+1)) {
        in.clear();
        ans.clear();
        REP(i,1,13) in.push_back( buf[i]-48 );

        REP(i,1,9) {
            tmp = in;
            tmp.push_back(i);
            sort(tmp.begin(), tmp.end());

            MSET(vis, false);
            if (check(tmp, 0, 0)) ans.push_back(i);
        }

        for (int i:ans) printf("%d\n", i);
    }
    return 0;
}
