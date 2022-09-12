class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> u;
        for(auto& v: edges){
            if(u.find(v[0]) != u.end()){
                if(u.find(v[1]) != u.end())
                    return v;
                u.insert(v[1]);
            }
            else if(u.find(v[1]) != u.end()){
                u.insert(v[0]);
            }
            else{
                u.insert(v[0]);
                u.insert(v[1]);
            }
        }
        return {};
    }
};