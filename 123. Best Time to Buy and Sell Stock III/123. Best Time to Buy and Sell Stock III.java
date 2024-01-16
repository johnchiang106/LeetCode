class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int maxDeal=4;
        int dp[][]=new int[maxDeal][n];
        
        for(int d[]:dp) Arrays.fill(d,Integer.MIN_VALUE);
        dp[0][0] = -prices[0];
        for (int i = 1; i < maxDeal && i < n; i++) {
            if(i%2 == 0) {
                dp[i][i] = dp[i-1][i-1] - prices[i];
            }
            else{
                dp[i][i] = dp[i-1][i-1] + prices[i];
            }
        }
        
        int ans = 0;
        for(int i = Math.min(n-1,maxDeal-1); i >= 0; i--){
            ans = Math.max(ans, f(i,n-1,dp,n,prices));
        }
        
        return ans;
    }
    public int f(int status,int day,int dp[][],int n,int p[])
    {
        if(day<0 || status<0)            return 0;
        if(dp[status][day] != Integer.MIN_VALUE)    return dp[status][day];
        int profit = f(status,day-1,dp,n,p);
        if(status%2 == 0)
        {
            int buy = -p[day] + f(status-1,day-1,dp,n,p);
            profit = (int)Math.max(profit,buy);
        }
        else
        {
            int sell = p[day] + f(status-1,day-1,dp,n,p);
            profit = (int)Math.max(profit,sell);
        }
        return dp[status][day]=profit;
    }
}
/*
 0  0  0  0  0  0  0  0
-3 -3 -3  0  0  0  0  0
 x  0  2  2  2  3  3  4
 x  x -5  2  2  2  2  2
 x  x  x -5  2  5  5  6


 0  0  0  0  0
-7 -6 -4 -3 -1
 x -1 -1 -1 -1
 x  x -5 -4 -2
 x  x  x -2 -2
 */