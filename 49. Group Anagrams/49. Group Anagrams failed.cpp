class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() <= 1) return vector<vector<string>>(1,strs);
        // vector<vector<string>> ans(1,vector<string>(1,strs[0]));
        vector<vector<string>> ans;
        
        for(auto& str: strs){
            bool f = false;
            for(auto& v: ans){
                if(sameAna(v[0],str)){
                    v.push_back(str);
                    f = true;
                    break;
                }
            }
            if(!f)  ans.push_back(vector<string>(1,str));
        }
        
        return ans;
    }
    bool sameAna(string& s1, string& s2){
        if(s1.size() != s2.size())  return false;
        
        m.clear();
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] == s2[i])  continue;
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for(auto& p: m)
            if(p.second != 0)   return false;
        return true;
    }
private:
    unordered_map<char,int> m;
};