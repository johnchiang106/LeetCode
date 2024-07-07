class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto result = unique(nums.begin(), nums.end());
	    return result - nums.begin();
    }
};