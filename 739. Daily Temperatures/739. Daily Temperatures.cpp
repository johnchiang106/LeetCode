class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        const int n = temp.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && temp[i] > temp[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};