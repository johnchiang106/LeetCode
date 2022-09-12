vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res(nums.size());
    int l = 0, r = nums.size()-1;
    for(int k = r; k >= 0; k--)
    {
        res[k] = (abs(nums[l]) > abs(nums[r])) ? nums[l] * nums[l++] : nums[r] * nums[r--];
    }
    
    return res;
}