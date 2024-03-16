class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(n,-100));
        vector<vector<bool>> cool(n,vector<bool>(n,false));
        dp[0][0] = -prices[0];
        for(int j = 1; j < n; ++j){
            dp[0][j] = max(dp[0][j-1], -prices[j]);
        }
        for(int i = 1; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(i%2 == 1){   //sell
                    if(dp[i-1][j-1] + prices[j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j-1] + prices[j];
                        cool[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else{   //buy
                    if(cool[i-1][j-1]){ //just sold, needs cooldown
                        dp[i][j] = max(dp[i-1][j-2] - prices[j], dp[i][j-1]);
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j-1] - prices[j], dp[i][j-1]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = n-1; i >= 0; --i){
            ans = max(ans, dp[i][n-1]);
        }
        return ans;
    }
};