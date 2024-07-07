class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();
        if(n == 1)  return (k > nums[0]) ? 1 : 0;
        int count = 0, j = 0;
        vector<int> nums2(nums.begin(),nums.end());
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n-i; ++j){
                if(k > nums2[j]) ++count;
                if(nums2[j] > k)    continue;
                nums2[j] *= nums[j+i];
            }
            if(k > nums2[n-i]) ++count;
        }
        if(k > nums2[0]) ++count;
        return count;
    }
};