class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums[0] > target)    return 0;
        return helper(nums, target);
    }
    int helper(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(mp.find(target) != mp.end()) return mp[target];
        int ans = 0;
        for(auto it = nums.rbegin(); it != nums.rend(); ++it){
            if(*it > target)    continue;
            ans += helper(nums, target - *it);
        }
        mp[target] = ans;
        return ans;
    }
    unordered_map<int, int> mp;
};