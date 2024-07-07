class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid, s = right;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid & 1){
                if(nums[mid] != nums[mid-1])    right = mid-1;
                else    left = mid+1;
            }
            else if(mid == s){
                return nums[mid];
            }
            else{
                if(nums[mid] != nums[mid+1]){
                    if(mid == 0 || nums[mid] != nums[mid-1]){
                        return nums[mid];
                    }
                    right = mid-1;
                }
                else    left = mid+1;
            }
        }
        return nums[left];
    }
};