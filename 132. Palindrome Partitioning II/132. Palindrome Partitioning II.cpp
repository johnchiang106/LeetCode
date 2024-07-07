class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        if(n <= 1)  return 0;
        vector<vector<bool>> dp;
        for(int i = 1; i <= n; i++){
            dp.push_back(vector<bool>(i,false));
            dp.back().back() = true;
        }
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if(s[i] == s[j] && (i == j+1 || dp[i-1][j+1]))
                    dp[i][j] = true;
        
        
        vector<int> dp2;
        for(int i = 0; i <= n; i++)
            dp2.push_back(i);
        
        for(int i = 2; i <= n; i++)
            for(int j = 0; j < i; j++)
                if(dp[i-1][j] && dp2[j]+1 < dp2[i])
                    dp2[i] = dp2[j] + 1;
        
        return dp2[n] - 1;
    }
};