class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, total = 0;
        unordered_map<int,int> um;
        ++um[0];
        for(int& num:nums){
            total += num;
            ++um[total];
            if(um.find(total-k) != um.end()){
                ans += um[total-k];
                if(k == 0)  --ans;
            }
        }
        return ans;
    }
};