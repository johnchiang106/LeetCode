class Solution {
    public int maxProfit(int k, int[] prices) {
        int n=prices.length;
        int maxDeal=k*2;
        int dp[][]=new int[maxDeal][n];
        
        for(int d[]:dp) Arrays.fill(d,Integer.MIN_VALUE);
        int m = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            m = Math.max(m, -prices[i]);
            dp[0][i] = m;
        }
        for (int i = 1; i < maxDeal; i++) {
            for (int j = i; j < n; j++) {
                if(i%2 == 0) {
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j-1] - prices[j]);
                }
                else{
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j-1] + prices[j]);
                }
            }
        }
        
        int ans = 0;
        for(int i = maxDeal-1; i >= 0; i--){
            ans = Math.max(ans, dp[i][n-1]);
        }
        
        return ans;
    }
}