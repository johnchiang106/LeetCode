class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        int dp[10001] = {0};
        for(int& i: nums){
            dp[i] += i;
            maxNum = max(maxNum,i);
        }
        dp[1] = max(dp[1],dp[0]);
        for(int i = 2; i <= maxNum; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }
        return dp[maxNum];
    }
};
