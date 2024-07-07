class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length, prefix = 1, suffix = 1;
        int[] ans = new int[n];
        Arrays.fill(ans,1);
        for(int i = 0; i < n; ++i){
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[n-1-i] *= suffix;
            suffix *= nums[n-1-i];
        }
        return ans;
    }
}