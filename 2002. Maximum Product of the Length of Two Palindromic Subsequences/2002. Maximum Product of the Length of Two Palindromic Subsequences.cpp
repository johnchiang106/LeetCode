class Solution {
public:
    int maxProduct(string s) {
        ss = s.size();
        int ans = 1;
        helper(ans, 0, s);
        return ans;
    }
private:
    int ss;
    string s1 = "", s2 = "";
    void helper(int& ans, int i, string& s){
        if(i >= ss){
            if(isPalindrome(s1) && isPalindrome(s2)){
                int a = s1.size() * s2.size();
                ans = max(ans, a);
            }
            return;
        }

        helper(ans, i+1, s);
        
        s1.push_back(s[i]);
        helper(ans, i+1, s);
        s1.pop_back();
        
        s2.push_back(s[i]);
        helper(ans, i+1, s);
        s2.pop_back();
    }
    bool isPalindrome(string &s){
        if(s.empty())   return false;
        for(int start = 0, end = s.size() - 1; start < end; ++start, --end)
            if(s[start] != s[end])
                return false;

        return true;
    }
};