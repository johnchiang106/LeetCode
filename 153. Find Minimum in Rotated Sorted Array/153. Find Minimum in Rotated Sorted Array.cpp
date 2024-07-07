class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        if(r == 0)  return nums[0];
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[l] < nums[mid])
                l = mid;
            else
                r = mid;
        }
        if(nums[l] < nums[l+1])  return nums[0];
        return nums[l+1];
    }
};