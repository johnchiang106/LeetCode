class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1)  return false;
        target >>= 1;
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_set<int> dp;
        dp.insert(0);
        vector<int> dp_next;
        dp_next.reserve(nums.size());
        for(auto it = nums.begin(); it != nums.end(); ++it){
            dp_next.clear();
            for(auto& ele: dp){
                if(ele + *it == target)   return true;
                if(ele + *it < target)   dp_next.push_back(ele + *it);
            }
            if(it == nums.end()-1)    break;
            for(auto& ele: dp_next){
                dp.insert(ele);
            }
        }
        return false;
    }
};