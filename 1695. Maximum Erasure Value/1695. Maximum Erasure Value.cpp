class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0, count = 0;
        for(int i = 0, j = 0; j < nums.size(); ++j){
            if(s.find(nums[j]) == s.end()){
                s.insert(nums[j]);
                count += nums[j];
                if(count > ans) ans = count;
            }
            else{
                while(nums[i] != nums[j]){
                    count -= nums[i];
                    s.erase(nums[i++]);
                }
                ++i;
            }
        }
        return ans;
    }
};