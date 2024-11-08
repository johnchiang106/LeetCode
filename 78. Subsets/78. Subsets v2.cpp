class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s = pow(2, nums.size());
        vector<vector<int>> ans;
        ans.reserve(s);
        ans.push_back(vector<int>());
        for(int& n: nums){
            for(int i = ans.size()-1; i >= 0; --i){
                ans.push_back(ans[i]);
                ans[i].push_back(n);
            }
        }
        return ans;
    }
};