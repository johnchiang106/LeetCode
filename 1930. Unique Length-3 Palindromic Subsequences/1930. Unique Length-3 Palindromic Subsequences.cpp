class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        bitset<26> exist;
        for (int i = 0; i != 26; ++i)
        {
            int l = s.find('a'+i);
            if (l != string::npos){
                int r = s.find_last_of('a'+i);
                if (r-l < 2) continue;
                for(int j = l+1; j != r; ++j){
                    exist.set(s[j]-'a');
                    if(exist.all()) break;
                }
                ans += exist.count();
                exist.reset();
            }
        }
        return ans;
    }
};