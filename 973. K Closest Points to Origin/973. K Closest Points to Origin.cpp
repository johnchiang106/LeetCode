class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if(n <= k)  return points;
        
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, mycomparison> pq;
        for(auto& v: points){
            pq.push(v);
            if(pq.size() > k)
                pq.pop();
        }
        ans.reserve(pq.size());
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
    class mycomparison
    {
    public:
        mycomparison(){}
        bool operator() (const vector<int>& v1, const vector<int>& v2) const
        {
          // if(v1.size() < 2 || v2.size() < 2)  return true;
          return v1[0]*v1[0] + v1[1]*v1[1] < v2[0]*v2[0] + v2[1]*v2[1];
        }
    };
};