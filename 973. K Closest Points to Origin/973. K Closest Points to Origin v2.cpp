class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if(n <= k)  return points;
        
        vector<pair<int,vector<int>>> q;
        for(auto& v: points){
            if(v.size() < 2)  continue;
            q.push_back({v[0]*v[0] + v[1]*v[1],v});
        }
        sort(q.begin(),q.end());
        vector<vector<int>> ans;
        ans.reserve(k);
        for(auto& p: q){
            ans.push_back(p.second);
            if(ans.size() == k) break;
        }
        return ans;
    }
};