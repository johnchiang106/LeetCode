class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(0);
        for(int i = prices.size()-1; i >= 0; --i){
            int curr = prices[i];
            while(st.top() > curr)
                st.pop();
            prices[i] = curr - st.top();
            st.push(curr);
        }
        return prices;
    }
};