class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ma = 0;
        for(int i = 0, j = nums.size()-1; i < j; ++i, --j)
            ma = max(ma, nums[i]+nums[j]);
        return ma;
    }
};