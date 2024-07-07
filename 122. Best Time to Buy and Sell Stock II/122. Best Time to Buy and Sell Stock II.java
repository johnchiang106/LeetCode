class Solution {
    public int maxProfit(int[] prices) {
        int left = 0, ans = 0;
        while(left < prices.length - 1){
            int right = left + 1;
            while(right < prices.length && prices[right] >= prices[right-1]){
                ++right;
            }
            --right;
            if(prices[right] > prices[left]){
                ans += prices[right] - prices[left];
            }
            left = right + 1;
        }
        return ans;
    }
}