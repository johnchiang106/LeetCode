class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        const int n = nums.size();
        int maxF = 1, i = 0, j = 1;
        sort(nums.begin(),nums.end());
        while(j < n){
            long long count = nums[j]-nums[j-1];
            count *= j-i;
            if(k >= count){
                k -= count;
                ++j;
            }
            else{
                k += nums[j-1]-nums[i];
                maxF = max(maxF,j-i);
                ++i;
            }
        }
        maxF = max(maxF,j-i);
        return maxF;
    }
};