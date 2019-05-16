#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
vector<int> init() {
    queue<int> q;
    vector<int> res;
    q.push(3);
    q.push(5);
    q.push(7);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        if (cur<100000000) {
            q.push(cur*10 + 3);
            q.push(cur*10 + 5);
            q.push(cur*10 + 7);
        }
    }
    return res;
}
bool check(int x) {
    int v3=0, v5=0, v7=0;
    while (x) {
        if (x%10 == 3) v3 = 1;
        if (x%10 == 5) v5 = 1;
        if (x%10 == 7) v7 = 1;
        x /= 10;
    }
    return v3 && v5 && v7;
}
int main()
{
    int n, ans;
    vector<int> nums = init();

    while (~scanf("%d", &n)) {
        ans = 0;
        for (int i: nums) if (i<=n && check(i)) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
