#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        multiset<pair<int,int>> s;
        
        for (int i=n-1; i>=0; i--) {
            if (s.size() && (*s.begin()).first<A[i]) {
                auto it = s.lower_bound( make_pair(A[i], -1) );
                it--;
                swap(A[i], A[(*it).second]);
                break;
            }
            s.insert( make_pair(A[i], i) );
        }
        return A;
    }
};
