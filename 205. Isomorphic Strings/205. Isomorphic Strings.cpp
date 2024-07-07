class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m, m2;
        for(int i = 0; i < s.size(); ++i){
            m.insert({s[i], t[i]});
            m2.insert({t[i], s[i]});
            if(m2[t[i]] != s[i])    return false;
            s[i] = m[s[i]];
        }
        return s == t;
    }
};