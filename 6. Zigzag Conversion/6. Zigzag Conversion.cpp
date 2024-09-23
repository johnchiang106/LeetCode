class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> rows(numRows, vector<char>());
        bool zig = true;
        for(auto it = s.begin(); it != s.end();){
            if(zig){
                for(auto& row: rows){
                    row.push_back(*it);
                    if(++it == s.end()) break;
                }
                zig = false;
            }
            else{
                int count = numRows - 2;
                while(count > 0){
                    rows[count--].push_back(*it);
                    if(++it == s.end()) break;
                }
                zig = true;
            }
        }
        string ans = "";
        for(auto& row: rows)
            for(char& ch: row)
                ans.push_back(ch);
        return ans;
    }
};