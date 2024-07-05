class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(3,0));

        for(int i = 0; i < m; ++i){
            int square = 0, temp = 0;
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '0'){
                    square = dp[j][2];
                    if(dp[j][0] != 0)
                        dp[j] = {0, 0, 0};
                    continue;
                }
                dp[j][0] = j == 0 ? 1 : dp[j-1][0] + 1;
                ++dp[j][1];
                temp = dp[j][2];
                dp[j][2] = min(square+1, min(dp[j][0], dp[j][1]));
                ans = max(ans, dp[j][2]);
                square = temp;
            }
        }

        return ans*ans;
    }
};