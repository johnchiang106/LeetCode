class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        int s = nums1.size();
        pairs.reserve(s);
        for(int i = 0; i < s; ++i){
            pairs.push_back({nums1[i],nums2[i]});
        }
        sort(pairs.begin(), pairs.end(), [](pair<int,int> a, pair<int, int> b){
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = -1;
        for(auto& p: pairs){
            if(pq.size() < k){
                sum += p.first;
                pq.push(p.first);
            }
            else if(pq.size() >= k && pq.top() < p.first){
                sum += p.first - pq.top();
                pq.push(p.first);
                pq.pop();
            }
            if(pq.size() == k){
                ans = max(ans, sum * p.second);
            }
        }
        return ans;
    }
};