class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)    return {-1, -1};
        int low = 0, high = nums.size()-1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                low = mid;
                high = mid;
                while(low >= 0 && nums[low] == target)   --low;
                while(high < nums.size() && nums[high] == target)   ++high;
                return {low+1, high-1};
            }
            else if(nums[mid] < target)  low = mid+1;
            else    high = mid-1;
        }
        return {-1, -1};
    }
};