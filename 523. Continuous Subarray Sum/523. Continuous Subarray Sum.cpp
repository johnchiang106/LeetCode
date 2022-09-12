class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int sum = nums.front() % k;
        unordered_set<int> s;
        
        s.insert(sum);
        for(int i = 1; i < n; ++i){
            if(nums[i]%k == 0){
                if(nums[i-1]%k == 0)
                    return true;
            }
            else{
                sum = (sum+nums[i]) % k;
                if(sum == 0 || s.find(sum%k) != s.end())
                    return true;
                s.insert(sum);
            }
        }
        return false;
    }
};