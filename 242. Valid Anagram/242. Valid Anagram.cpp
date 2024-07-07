class Solution {
public:
    bool isAnagram(string s, string t) {
        const int n = s.size();
        if(n != t.size())    return false;
        unordered_map<char,int> m;
        for(int i = 0; i < n; ++i){
            if(s[i] == t[i])    continue;
            // ++m[s[i]], --m[t[i]];
            if(++m[s[i]] > n-i-1 || --m[t[i]] < -n+i+1)
                return false;
        }
        for(auto& p: m)
            if(p.second != 0)   return false;
        return true;
    }
};