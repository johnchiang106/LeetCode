class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if(n <= k)  return points;
        
        priority_queue<pair<int,vector<int>>> pq;
        for(auto& v: points){
            pq.push({v[0]*v[0] + v[1]*v[1],v});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        ans.reserve(k);
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};