class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1, n = nums.size(), zpos;
        bool zero = false;
        vector<int> ans(n,0);
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0){
                if(zero)    return ans;
                else{
                    zero = true;
                    zpos = i;
                }
            }
            else    pro *= nums[i];
        }
        if(zero)    ans[zpos] = pro;
        else
            for(int i = 0; i < n; ++i)
                ans[i] = pro/nums[i];
        return ans;
    }
};