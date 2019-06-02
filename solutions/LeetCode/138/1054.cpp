#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> res;
        map<int,int> mp;
        set<pair<int,int>> s;
        for (int i:barcodes) mp[i]++;
        for (auto i:mp) s.insert( make_pair(i.second, i.first) );
        
        int cnt=0;
        while (cnt<n) {
            auto i = *s.rbegin();
            s.erase(s.find(i));
            res.push_back(i.second);
            cnt++;
            
            auto j = make_pair(-1,-1);
            if (s.size()) {
                j = *s.rbegin();
                s.erase(s.find(j));
                res.push_back(j.second);
                cnt++;
            }
            
            if (i.first > 1) s.insert(make_pair(i.first-1, i.second));
            if (j.first > 1) s.insert(make_pair(j.first-1, j.second));
        }
        return res;
    }
};
