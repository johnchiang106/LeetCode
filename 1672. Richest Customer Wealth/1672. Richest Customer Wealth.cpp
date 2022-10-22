class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(const auto& person: accounts)
            ans = max(ans,accumulate(person.begin(),person.end(),0));
        return ans;
    }
};