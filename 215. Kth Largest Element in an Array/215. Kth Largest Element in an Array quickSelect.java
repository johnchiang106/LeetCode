class Solution {
    public int partition(int[] nums, int left, int right){
        int pivot = nums[right];
        int i = left;
        for(int j = left; j <= right; ++j){
            if(nums[j] <= pivot){
                if(i != j){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                ++i;
            }
        }
        return i-1;
    }
    public int quickSelect(int[] nums, int left, int right, int k){
        int index = partition(nums, left, right);
        if(index > k){
            return quickSelect(nums, left, index-1, k);
        }
        if(index < k){
            return quickSelect(nums, index+1, right, k);
        }
        return nums[index];
    }
    public int findKthLargest(int[] nums, int k) {
        if(nums.length == 1){
            return nums[0];
        }
        return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    }
}