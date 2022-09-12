class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = size(nums);
        for(int l = 0, r = 0; r < n; r++) {
            if(nums[r] == 0)
                if(k == 0)
                    while(nums[l++] != 0);       
                else k--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};