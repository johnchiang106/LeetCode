class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ma = prices.back(), ans = 0;
        for(auto rit = prices.rbegin(); rit != prices.rend(); ++rit){
            if(*rit > ma){
                ma = *rit;
                continue;
            }
            ans = max(ans, ma - *rit);
        }
        return ans;
    }
};