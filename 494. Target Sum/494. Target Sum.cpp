class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) & 1)
        return 0;
    target = (sum - target) / 2;
    // dp[j] := the number of ways to sum to j
    // The chosen idice sum = x, the non-chosen idice sum = sum-x.
    // Chosen - non-chosen needs to equal target.
    // 2x - sum = target  ==>  x needs to equal (sum+target)/2
    // the summing vector is always symmetric, so the value at (sum+target)/2 is equal to (sum-target)/2
    vector<int> dp(target + 1);
    dp[0] = 1;

    for (int& num: nums)
        for (int j = target; j >= num; --j)
            dp[j] += dp[j - num];

    return dp[target];
  }
};