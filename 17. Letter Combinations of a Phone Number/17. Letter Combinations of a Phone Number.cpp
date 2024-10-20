class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int ds = digits.size();
        ans.reserve(pow(3,ds));
        for(char& digit: digits){
            int s = ans.size();
            if(s == 0){
                for(const char& ch: letters[digit-'2'])
                    ans.push_back(string(1,ch));
                continue;
            }
            int s2 = letters[digit-'2'].size()-1;
            for(int j = 0; j < s * s2; ++j)
                ans.push_back(ans[j]);
            for(int j = 0; j <= s2; ++j)
                for(int k = 0; k < s; ++k)
                    ans[j*s+k].push_back(letters[digit-'2'][j]);
        }
        return ans;
    }
private:
    const vector<vector<char>> letters = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
};