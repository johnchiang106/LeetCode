class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int minValue = nums[0];
        for(auto& n: nums){
            while(!st.empty() && st.top().second <= n){
                st.pop();
            }
            if(!st.empty() && st.top().first < n){
                return true;
            }
            else{
                st.push({minValue, n});
                minValue = min(minValue, n);
            }
        }
        return false;
    }
};