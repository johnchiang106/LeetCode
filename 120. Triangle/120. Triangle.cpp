class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int s = triangle.size();
        vector<int> dp(s, 10000);
        dp[0] = triangle[0][0];
        for(int i = 1; i < s; ++i){
            vector<int>& curr = triangle[i];
            int last = dp[0];
            for(int j = 0; j <= i; ++j){
                if(j == 0)
                    dp[0] += curr[0];
                else if(j == i)
                    dp[j] = last + curr[j];
                else{
                    int temp = dp[j];
                    dp[j] = min(last, dp[j]) + curr[j];
                    last = temp;
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};