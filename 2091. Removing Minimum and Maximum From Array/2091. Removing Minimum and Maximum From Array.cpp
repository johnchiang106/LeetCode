class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 2)  return n;
        
        int mi = 0, ma = 0;
        for(int i = 1; i < n; ++i){
            if(nums[i] < nums[mi])  mi = i;
            if(nums[i] > nums[ma])  ma = i;
        }
        
        return min({max(mi, ma) + 1, 
                    n - min(mi, ma), 
                    min(mi, ma) + 1 + n - max(mi, ma)});
    }
};