class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        set<int> valid;
        for(int i = 0; i < n; ++i)  valid.insert(i);
        
        map<int,set<int>> m;
        for(auto& v: edges){
            m[v[0]].insert(v[1]);
            m[v[1]].insert(v[0]);
        }
        bool cleaning = true;
        while(cleaning){
            cleaning = false;
            for(auto it = m.begin(); it != m.end(); ++it){
                if(it->second.size() == 1){
                    m[*(it->second.begin())].erase(it->first);
                    m.erase(it->first);
                    cleaning = true;
                }
            }
        }
        for(auto it = edges.rbegin(); it != edges.rend(); ++it){
            if(m.find((*it)[0]) != m.end() && 
               m.find((*it)[1]) != m.end())    return *it;
        }
        return {0,0};
    }
};