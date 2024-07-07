class Solution {
public:
    struct Compare {
        bool operator()(const string& a, const string& b) const {
            if(a.size() != b.size())
                return a.size() > b.size();
            return a > b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> pq;
        for(string& str: nums){
            pq.push(str);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};