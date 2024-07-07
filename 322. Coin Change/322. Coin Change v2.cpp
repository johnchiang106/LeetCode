class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1, amount+1);
        for(int& coin: coins){
            if(coin > amount)   continue;
            dp[coin] = 1;
            for(int i = coin+1; i <= amount; ++i){
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};