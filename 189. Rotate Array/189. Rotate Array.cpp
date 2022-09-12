class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        k %= s;
        nums.insert(nums.end(),nums.begin(),nums.begin()+s-k);
        nums.erase(nums.begin(),nums.begin()+s-k);
        // vector<int> sub1 {&nums[0], &nums[nums.size()-k]};
        // vector<int> sub2 {nums.begin()+nums.size()-k, nums.end()};
        // sub2.insert(sub2.end(), sub1.begin(), sub1.end());
        // nums = sub2;
    }
};