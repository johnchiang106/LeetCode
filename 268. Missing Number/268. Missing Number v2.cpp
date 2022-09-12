class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size(), mask = 0;
        
        for(int i = nums.size()-1; i >= 0; --i){
            ans ^= nums[i];
            mask ^= i;
        }
        
        return ans^mask;
    }
};