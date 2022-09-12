class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0;
        for(auto& n: s){
            if(s.count(n-1))    continue;
            int j = 1;
            while(s.count(n+j)) ++j;
            if(j > ans) ans = j;
        }
        return ans;
    }
};