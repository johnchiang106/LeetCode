class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> coins2;
        
        coins2.reserve(coins.size());
        vector<int> dp(amount+1, -1);
        for(int& n: coins){
            if(n < amount){
                coins2.push_back(n);
                dp[n] = 1;
            }
            else if(n == amount)
                return 1;
        }
        for(int i = 1; i <= amount; ++i){
            if(dp[i] == -1)  continue;
            for(int& n: coins2){
                if(i+n > amount) continue;
                if(dp[i+n] == -1 || dp[i+n] > dp[i]+1)
                    dp[i+n] = dp[i] + 1;
            }
        }
        return dp[amount];
    }
};