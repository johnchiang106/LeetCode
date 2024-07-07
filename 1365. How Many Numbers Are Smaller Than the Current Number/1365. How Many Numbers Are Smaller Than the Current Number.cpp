class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> nums2 = nums, ans;
        sort(nums2.begin(), nums2.end());
        for(auto n: nums){
            ans.push_back(lower_bound(nums2.begin(), nums2.end(), n) - nums2.begin());
        }
        return ans;
    }
};