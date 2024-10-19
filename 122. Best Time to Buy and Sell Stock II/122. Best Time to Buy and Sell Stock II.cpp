class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(auto it = prices.begin()+1; it != prices.end(); ++it){
            if(*(it-1) < *it){
                ans += *it - *(it-1);
            }
        }
        return ans;
    }
};