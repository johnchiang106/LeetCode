class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0, p = 0;
        for(int i = 0; i < s.size(); i++)
            (s[i] == '#') ? k = max(0,k-1) : s[k++] = s[i];
        for(int i = 0; i < t.size(); i++)
            (t[i] == '#') ? p = max(0,p-1) : t[p++] = t[i];
        
        if(k != p)    return false;
        for(int i = 0; i < k; i++)
            if(s[i] != t[i])  return false;

        return true;
    }
};