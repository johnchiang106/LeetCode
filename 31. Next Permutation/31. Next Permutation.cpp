class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        int i = n-1;
        while(i > 0){
            if(nums[i-1] < nums[i]) break;
            --i;
        }
        
        if(i > 0){
            for(int j = i+1; j <= n; ++j){
                if(j == n || nums[i-1] >= nums[j]){
                    swap(nums[i-1],nums[j-1]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};