class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> count;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int& n: arr)
            ++count[n];
        for(auto& p: count)
            pq.emplace(p.second);
        while(k >= pq.top()){
            k -= pq.top();
            pq.pop();
        }
        return pq.size();
    }
};