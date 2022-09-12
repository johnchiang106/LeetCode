class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i < j; ++i, --j){
            while(!isalnum(s[i]) && i < j)
                ++i;
            if(isupper(s[i]))
                s[i] += 'a'-'A';
            
            while(!isalnum(s[j]) && i < j)
                --j;
            if(isupper(s[j]))
                s[j] += 'a'-'A';
            
            if(s[i] != s[j])    return false;
        }
        return true;
    }
};