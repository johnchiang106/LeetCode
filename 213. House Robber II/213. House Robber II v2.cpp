class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        int left = 0, right = nums[0];
        for(int i = 1; i < n; ++i){
            int temp = right;
            right = max(left+nums[i], right);
            left = temp;
        }
        int ans = right;
        left = 0;
        right = 0;
        for(int i = 1; i <= n; ++i){
            int temp = right;
            right = max(left+nums[i], right);
            left = temp;
        }
        return max(ans, right);
    }
};