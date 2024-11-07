class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        vector<int> curr;
        backtrack(ans, nums, curr, k, 0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int k, int i){
        if(k == 0){
            ans.push_back(curr);
            return;
        }
        for(int j = i; j < nums.size()-k+1; ++j){
            curr.push_back(nums[j]);
            backtrack(ans, nums, curr, k-1, j+1);
            curr.pop_back();
        }
    }
};