class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();
        if(n == 1)  return (k > nums[0]) ? 1 : 0;
        int i = 0, j = 0, prevj = -1, p = nums[0], count = 0;
        while(j <= n-1 || p > k){
            if(p >= k){
                p /= nums[i++];
                if(i > j)
                    p *= nums[++j];
            }
            else{
                while(p < k && j < n-1)
                    p *= nums[++j];
                if(p < k)   ++j;
                count += (j-i)*(j-i+1)/2;
                if(prevj != -1)
                    count -= (prevj-i)*(prevj-i+1)/2;
                prevj = j;
            }
        }
        return count;
    }
};