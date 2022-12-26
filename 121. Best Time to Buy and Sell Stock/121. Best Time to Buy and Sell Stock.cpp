class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0, minP = prices[0];
        for(auto& p: prices){
            minP = min(minP,p);
            ans = max(ans,p-minP);
        }
        return ans;
    }
};