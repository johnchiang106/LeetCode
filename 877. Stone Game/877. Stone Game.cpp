class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int s = piles.size()+1, sum = 0;
        vector<vector<int>> dp(s, vector<int>(s,0));
        for(int i = 1; i < s; ++i){
            if(i & 1){
                dp[0][i] = dp[0][i-1] + piles[i-1];
                dp[i][0] = dp[i-1][0] + piles[s-1-i];
            }
            else{
                dp[0][i] = dp[0][i-1] - piles[i-1];
                dp[i][0] = dp[i-1][0] - piles[s-1-i];
            }
        }
        for(int i = 1; i < s; ++i){
            for(int j = 1; j < s; ++j){
                if(i+j > s-1) continue;
                if((i+j) & 1){
                    dp[i][j] = max(dp[i-1][j] + piles[i-1], dp[i][j-1] + piles[s-1-j]);
                }
                else{
                    dp[i][j] = min(dp[i-1][j] - piles[i-1], dp[i][j-1] - piles[s-1-j]);
                }
            }
        }
        // for(int i = 0; i < s; ++i){
        //     for(int j = 0; j < s; ++j){
        //         printf("%i, ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        for(int i = s-1; i >= 0; --i)
            if(dp[s-1-i][i] > 0)    return true;
        return false;
    }
};