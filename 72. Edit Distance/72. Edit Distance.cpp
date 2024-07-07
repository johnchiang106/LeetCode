class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp;
        for(int i = 0; i <= s1; i++){
            vector<int> v;
            for(int j = 0; j <= s2; j++)
                v.push_back(0);
            dp.push_back(v);
        }
        for(int i = 0; i <= s1; i++) dp[i][0] = i;
        for(int j = 0; j <= s2; j++) dp[0][j] = j;
        
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int erase = dp[i-1][j];
                    int insert = dp[i][j-1];
                    int replace = dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min({erase, insert, replace});
                }
            }
        }
        return dp[s1][s2];
    }
};