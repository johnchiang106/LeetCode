class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], curMin = 1, curMax = 1;
        
        for(int& n: nums){
            if(n == 0){
                curMax = 0, curMin = 0;
            }
            else if(n > 0){
                curMax = max(curMax * n, n);
                curMin = min(n * curMin, n);
            }
            else{
                int tmp = curMax * n;
                curMax = max(n * curMin, n);
                curMin = min(tmp, n);
            }
            ans = max(ans, curMax);
        }
        
        return ans;
    }
};
