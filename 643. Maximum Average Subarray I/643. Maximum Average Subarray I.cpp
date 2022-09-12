class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = 0, total = 0, n = size(nums);
        for(int i = 0; i < k; ++i)
            total += nums[i];
        ans = total;
        for(int i = k; i < n; ++i){
            total += nums[i]-nums[i-k];
            ans = max(ans,total);
        }
        return double(ans)/k;
    }
};