class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, j = 0, n = s.size();
        for(int i = n-1; i > 0; i -= max(1,j), ans += j, j = 0)
            while(i-1-j >= 0 && i+j < n && 
                  s[i+j] == s[i] && s[i-1-j] != s[i+j])
                ++j;
        return ans;
    }
};