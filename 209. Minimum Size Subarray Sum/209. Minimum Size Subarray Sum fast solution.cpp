class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int minlen=nums.size()+1;
        int sum=0;
        while(right<nums.size())
        {
            sum+=nums[right++];
            while(sum>=target)
            {
                minlen=min(minlen,right - left);
                sum-=nums[left++];
            }
        }
        return(minlen==nums.size()+1)?0:minlen;  
    }
};