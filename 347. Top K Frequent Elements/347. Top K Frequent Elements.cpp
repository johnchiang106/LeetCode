class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int& n: nums){
            um[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComp> pq;
        for(auto& p: um){
            pq.push(p);
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
private:
    struct MyComp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        }
    };
};