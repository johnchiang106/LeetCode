class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for(int i = prices.size()-1; i >= 0; --i){
            while(!st.empty() && prices[i] < st.top())
                st.pop();
            int temp = prices[i];
            if(!st.empty())
                prices[i] -= st.top();
            st.push(temp);
        }
        return prices;
    }
};