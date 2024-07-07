class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> v1, v2;
        for(int i = 0; i < s.size(); ++i){
            int pos = find(v2.begin(),v2.end(),t[i]) - v2.begin();
            if(pos != v2.size()){
                if(v1[pos] != s[i]) return false;
                else    continue;
            }
            pos = find(v1.begin(),v1.end(),s[i]) - v1.begin();
            if(pos == v1.size()){
                v1.push_back(s[i]);
                v2.push_back(t[i]);
            }
            else if(v2[pos] != t[i])    return false;
        }
        return true;
    }
};