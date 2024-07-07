class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0], p = 1, ans = 1;
        for(auto& n: nums){
            if(n != curr){
                nums[p++] = n;
                curr = n;
                ++ans;
            }
        }
        return ans;
    }
};