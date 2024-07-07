class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        set<int> valid;
        for(int i = 0; i < n; ++i)  valid.insert(i);
        
        vector<set<int>> vec(n,set<int>());
        for(auto& v: edges){
            vec[v[0]-1].insert(v[1]-1);
            vec[v[1]-1].insert(v[0]-1);
        }
        bool cleaning = true;
        while(cleaning){
            cleaning = false;
            for(int i = 0; i < n; ++i){
                if(vec[i].size() == 1){
                    valid.erase(i);
                    vec[*(vec[i].begin())].erase(i);
                    vec[i].clear();
                    cleaning = true;
                }
            }
        }
        for(auto it = edges.rbegin(); it != edges.rend(); ++it){
            if(valid.find((*it)[0]-1) != valid.end() && 
               valid.find((*it)[1]-1) != valid.end())    return *it;
        }
        return {0,0};
    }
};