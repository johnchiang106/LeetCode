class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<map<int,int>>> com(target+1, set<map<int,int>>());
        for(int& can: candidates){
            if(can > target)  continue;
            map<int,int> temp;
            temp[can] = 1;
            com[can].insert(temp);
        }
        for(int i = 1; i <= target; ++i){
            for(int& can: candidates){
                if(can >= i)  continue;
                for(auto mp: com[i-can]){
                    ++mp[can];
                    com[i].insert(mp);
                }
            }
        }
        vector<vector<int>> ans;
        ans.reserve(com[target].size());
        for(auto& mp: com[target]){
            vector<int> vec;
            for(auto& p: mp){
                for(int i = 0; i < p.second; ++i){
                    vec.push_back(p.first);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};