class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pprev = 0, prev = nums[0];
        for(int i = 1; i < n; i++){
            int pick = nums[i] + pprev;
            pprev = prev;
            prev = max(pick,prev);
        }
        return prev;
    }
};