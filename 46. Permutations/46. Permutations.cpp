class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans, int& n){
        if(index >= n){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < n; ++i){
            swap(nums[i], nums[index]);
            solve(index + 1, nums, ans, n);
            swap(nums[index], nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        for(int j = 2; j <= n; ++j) i *= j;
        vector<vector<int>> ans;
        ans.reserve(i);
        solve(0, nums, ans, n);
        return ans;
    }
};