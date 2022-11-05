class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        return accumulate(nums.begin(), nums.end(), 0, [](int x, int y) { return x^y; });
    }
};