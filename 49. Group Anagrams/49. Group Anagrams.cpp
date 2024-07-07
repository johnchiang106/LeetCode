class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> m;
        for(auto& str: strs){
            map<char,int> temp;
            for(auto& c: str)
                temp[c]++;
            if(m.find(temp) != m.end())
                m[temp].push_back(str);
            else
                m[temp] = vector<string>(1,str);
        }
        vector<vector<string>> ans;
        ans.reserve(m.size());
        for(auto& p: m)
            ans.push_back(p.second);
        return ans;
    }
};