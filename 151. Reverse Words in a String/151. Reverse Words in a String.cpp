class Solution {
public:
    string reverseWords(string s) {
        string ans;
        ans.reserve(s.size()+1);
        for(int i = s.size() - 1; i >= 0; --i){
            while(i >= 0 && s[i] == ' ')  --i;
            if(i < 0)   break;
            auto j = s.begin() + i + 1;
            while(i >= 0 && s[i] != ' ')  --i;
            ans += string(s.begin() + i + 1, j) + " ";
        }
        ans.pop_back();
        return ans;
    }
};