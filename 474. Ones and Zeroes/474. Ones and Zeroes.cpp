class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(string& str: strs){
            int ones = 0, zeros = 0;
            for(char& ch: str){
                if(ch == '1')	++ones;
                else		++zeros;
            }
            for(int j = m; j >= zeros; --j)
                for(int k = n; k >= ones; --k)
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);
        }
        int ans = 0;
        for(int j = m; j > 0; --j)
            for(int k = n; k > 0; --k)
                ans = max(dp[j][k], ans);
        return ans;
    }
};