class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), prev=0, sum=0;
        unordered_set<int> s;
        for (int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;
            if (s.find(sum) != s.end()) return true;
            s.insert(prev);
            prev = sum;
        }
        return false;
    }
};