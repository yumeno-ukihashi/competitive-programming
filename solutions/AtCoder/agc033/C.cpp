#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
int n,dis[M];
vector<int> e[M];
queue<int> q;
int bfs(int cur) {
    MSET(dis, 0);
    dis[cur] = 1;
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i: e[cur]) if (!dis[i]) {
            dis[i] = dis[cur]+1;
            q.push(i);
        }
    }
    return max_element(dis+1, dis+n+1) - dis;
}
int main()
{
    while (~scanf("%d",&n)) {
        REP(i,1,n) e[i].clear();
        REP(i,1,n-1) {
            int x,y;
            scanf("%d %d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }

        int root = 1;
        root = bfs(root);
        root = bfs(root);
        printf("%s\n", dis[root]%3==2 ? "Second" : "First");
    }
    
    return 0;
}

