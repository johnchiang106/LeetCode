class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        auto minMax = minmax_element(nums.begin(), nums.end());
        
        int i = minMax.first - nums.begin();
        int j = minMax.second - nums.begin();
        
		// Making sure i <= j
        if (i > j) swap(i, j);
		
        return min({n-(j-i+1)+2, n-i, j+1});
    }
};