class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        const int n = nums.size();
        long long sum = 0;
        pair<int,int> sub;
        for(int i = 0; i < n; ++i){
            sub = {nums[i],nums[i]};
            for(int j = i+1; j < n; ++j){
                sub.first = max(sub.first,nums[j]);
                sub.second = min(sub.second,nums[j]);
                sum += sub.first - sub.second;
            }
        }
        return sum;
    }
};