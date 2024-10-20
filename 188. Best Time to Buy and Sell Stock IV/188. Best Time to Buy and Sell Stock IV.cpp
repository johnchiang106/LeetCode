class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size(), tran = min(k*2, days);
        vector<vector<int>> dp(tran, vector<int>(days,0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < days; ++i){
            dp[0][i] = max(dp[0][i-1], -prices[i]);
        }
        for(int i = 1; i < tran; ++i){
            int p = (i & 1) ? 1 : -1;
            dp[i][i] = dp[i-1][i-1] + p*prices[i];
            for(int j = i+1; j < days; ++j){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+p*prices[j]);
            }
        }
        int ans = 0;
        for(auto& vec: dp){
            ans = max(ans, vec.back());
        }
        return ans;
    }
};