class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int n = stones.size();
        dp.assign(n,vector<int>(n,-1));

        int sum = accumulate(stones.begin(),stones.end(),0);
        return solve(stones,0,n-1,sum);
    }
    int solve(vector<int>& stones, int i, int j, int sum){
        if(i == j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int remove_front = sum - stones[i] - solve(stones,i+1,j,sum);
        int remove_back = sum - stones[j] - solve(stones,i,j-1,sum);

        dp[i][j] = max(remove_front,remove_back);
        return dp[i][j];
    }
private:
    vector<vector<int>> dp;
};