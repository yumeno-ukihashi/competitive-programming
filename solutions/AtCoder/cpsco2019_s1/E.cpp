#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 300005
#define L (cur*2)
#define R (L+1)
using namespace std;
struct Q {int l,r,x;} ask[M];
int n,m,q,in[M];
int cnt[M*8], tree[M*8], lazy[M*8];
vector<int> lisan;

void init() {
    MSET(tree, 0);
    MSET(lazy, 0);
    MSET(cnt, 0);
    lisan.clear();
    REP(i,1,n) {
        scanf("%d",&in[i]);
        lisan.push_back(in[i]);
    }
    REP(i,1,q) {
        scanf("%d %d %d",&ask[i].l,&ask[i].r,&ask[i].x);
        lisan.push_back(ask[i].x);
    }

    sort(lisan.begin(), lisan.end());
    lisan.resize( unique(lisan.begin(), lisan.end()) - lisan.begin() );
    m = lisan.size();
    REP(i,1,n) in[i] = lower_bound(lisan.begin(), lisan.end(), in[i]) - lisan.begin() + 1;
    REP(i,1,q) {
        ask[i].l = lower_bound(lisan.begin(), lisan.end(), ask[i].l) - lisan.begin() + 1;
        ask[i].r = upper_bound(lisan.begin(), lisan.end(), ask[i].r) - lisan.begin();
        ask[i].x = lower_bound(lisan.begin(), lisan.end(), ask[i].x) - lisan.begin() + 1;
        if (ask[i].l>m || ask[i].r<=0) {
            ask[i].l = ask[i].r = -1;
        }
        if (ask[i].l > ask[i].r) {
            ask[i].l = ask[i].r = -1;
        }
        if (ask[i].r>m) ask[i].r = m;
    }
}
void push(int cur,int ll,int rr) {
    if (ll==rr) return;
    if (!lazy[cur]) return;
    tree[L] = tree[R] = 0;
    cnt[L] = cnt[R] = 0;
    lazy[L] = lazy[R] = true;
    lazy[cur] = 0;
}
void upd(int cur,int ll,int rr,int l,int r,int a) {
    push(cur, ll, rr);
    if (ll==l && rr==r) {
        if (a== 1) {
            tree[cur] ^= lisan[ll-1];
            cnt[cur] ++;
        }
        if (a==-1) {
            tree[cur] = 0;
            cnt[cur] = 0;
            lazy[cur] = 1;
        }
        return;
    }

    int mid = (ll+rr)/2;
    if (r<=mid) upd(L, ll, mid, l, r, a);
    else if (l>mid) upd(R,mid+1, rr, l, r, a);
    else {
        upd(L, ll, mid, l, mid, a);
        upd(R, mid+1, rr, mid+1, r, a);
    }
    tree[cur] = tree[L] ^ tree[R];
    cnt[cur] = cnt[L] + cnt[R];
}
int que(int cur,int ll,int rr,int l,int r) {
    push(cur, ll, rr);
    if (ll==l && rr==r) return tree[cur];

    int mid = (ll+rr)/2;
    if (r<=mid) return que(L, ll, mid, l, r);
    else if (l>mid) return que(R, mid+1, rr, l, r);
    else return que(L, ll, mid, l, mid) ^ que(R, mid+1, rr, mid+1, r);
}
int que2(int cur,int ll,int rr,int l,int r) {
    push(cur, ll, rr);
    if (ll==l && rr==r) return cnt[cur];

    int mid = (ll+rr)/2;
    if (r<=mid) return que2(L, ll, mid, l, r);
    else if (l>mid) return que2(R, mid+1, rr, l, r);
    else return que2(L, ll, mid, l, mid) + que2(R, mid+1, rr, mid+1, r);
}
int main()
{
    while (~scanf("%d %d",&n,&q)) {
        init();
        REP(i,1,n) upd(1, 1, m, in[i], in[i], 1);

        REP(i,1,q) {
            if (ask[i].l==-1) {
                puts("0");
                continue;
            }

            int x = que(1,1,m,ask[i].l,ask[i].r);
            int c = que2(1,1,m,ask[i].l,ask[i].r);
            upd(1,1,m,ask[i].l,ask[i].r,-1); 
            if (c%2) upd(1,1,m,ask[i].x,ask[i].x,1);

            printf("%d\n", x);
        }
    }
    return 0;
}

