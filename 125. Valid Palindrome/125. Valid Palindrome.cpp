class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(auto& c: s){
            if(c <= 'Z' && c >= 'A')
                s2.push_back(c+'a'-'A');
            else if((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))
                s2.push_back(c);
        }
        for(int i = 0, j = s2.size()-1; i < j; ++i, --j)
            if(s2[i] != s2[j])    return false;
        return true;
    }
};