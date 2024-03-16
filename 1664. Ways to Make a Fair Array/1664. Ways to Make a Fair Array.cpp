class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0, n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(i&1) s3 += nums[i];
            else    s4 += nums[i];
        }
        for(int i = 0; i < n; i++){
            if(i&1) s3 -= nums[i];
            else   s4 -= nums[i];
            
            if(s1 + s4 == s2 + s3)
                ++ans;
            
            if(i&1) s1 += nums[i];
            else   s2 += nums[i];
        }
        return ans;
    }
};