class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for(int& n: nums)   if(n >= target) return 1;
        
        vector<int> nums2(nums.begin(), nums.end()-1);
        for(int count = 1; count < nums.size(); ++count){
            auto it2 = nums2.begin();
            for(int i = count; i < nums.size(); ++i, ++it2){
                *it2 += nums[i];
                if(*it2 >= target)   return  count+1;
            }
        }
        
        return 0;
    }
};