class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size(), ss = s.size();
        for(int i = 1; i < ss; ++i){
            int j = 1;
            while(j <= i && i+j <= ss && s[i-j] == s[i+j-1]){
                ++ans, ++j;
            }
            j = 1;
            while(j <= i && i+j < ss && s[i-j] == s[i+j]){
                ++ans, ++j;
            }
        }
        return ans;
    }
};