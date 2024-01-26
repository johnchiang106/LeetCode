class Solution {
    public long minimumDifference(int[] nums) {
        int n3 = nums.length;
        int n2 = n3*2/3, n = n3/3;
        int[] currRow = new int[n2+1];
        for(int i = 1; i <= n2; ++i){
            currRow[i] = (i <= n) ? currRow[i-1] + nums[i-1] : currRow[i-1] - nums[i-1];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n2; ++j){
                int left = (j <= n) ? currRow[j-1] + nums[i+j-1] : currRow[j-1] - nums[i+j-1];
                currRow[j] = Math.min(currRow[j], left);
            }
        }
        return currRow[n2];
    }
}