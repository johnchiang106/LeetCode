class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums[0], s = nums.size()-1;
        for(int j = 1; j <= i && i < s; ++j){
            i = max(i, j + nums[j]);
        }
        return i >= s;
    }
};