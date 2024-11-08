class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int s = pow(2, nums.size());
        vector<vector<int>> ans;
        ans.reserve(s);
        ans.push_back(vector<int>());
        unordered_map<int,int> mp;
        for(int& n: nums)
            ++mp[n];
        for(auto& p: mp){
            int c = p.second;
            int back = ans.size();
            while(c-- > 0){
                for(int i = 0; i < back; ++i){
                    ans.push_back(ans[i]);
                    ans[i].push_back(p.first);
                }
            }
        }
        return ans;
    }
};