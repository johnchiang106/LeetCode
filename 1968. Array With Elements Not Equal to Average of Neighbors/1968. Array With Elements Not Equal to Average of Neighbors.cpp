class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = (nums.size() & 1) ? 0 : 1;
        for(int j = nums.size()-2; i < j; i += 2, j -= 2){
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};