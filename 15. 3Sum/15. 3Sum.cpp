class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i <= n-3; ++i){
            int j = i+1, k = n-1;
            while(j <= k-1){
                int temp = nums[i] + nums[j] + nums[k];
                if(temp == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(nums[j] == nums[j+1] && j != k-1) ++j;
                    while(nums[k] == nums[k-1] && j != k-1) --k;
                    ++j, --k;
                    continue;
                }
                else if(temp < 0)   ++j;
                else    --k;
            }
            while(nums[i] == nums[i+1] && i < n-3)  ++i;
        }
        return ans;
    }
};