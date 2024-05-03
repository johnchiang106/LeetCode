class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int gap = 0;
        unordered_map<int,int> mp;
        for(auto& vec: wall){
            int pos = 0;
            for(auto it = vec.begin(); it != vec.end() - 1; ++it){
                pos += *it;
                gap = max(gap, ++mp[pos]);
            }
        }
        return wall.size() - gap;
    }
};