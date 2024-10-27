class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        for(int j = 2; j <= n; ++j) i *= j;
        vector<vector<int>> ans;
        ans.reserve(i);
        solve(0, nums, ans, n);
        return ans;
    }
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans, int& n){
        if(index >= n){
            ans.push_back(nums);
            return;
        }
        solve(index+1, nums, ans, n);
        set<int> st;
        st.insert(nums[index]);
        for(int i = index+1; i < n; ++i){
            if(st.count(nums[i]))  continue;
            st.insert(nums[i]);
            swap(nums[i], nums[index]);
            solve(index+1, nums, ans, n);
            swap(nums[index], nums[i]);
        }
        return;
    }
};