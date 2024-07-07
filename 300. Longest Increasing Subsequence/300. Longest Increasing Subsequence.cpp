class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = i-1; j >= 0; --j){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};