class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k % 2 == 1)  return -1;
        
        int ans = k < n ? nums[k] : nums.front();
        n = min(k-1,n);
        
        for(int i = 0; i < n; ++i)
            if(nums[i] > ans)   ans = nums[i];
        return ans;
    }
};