class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        string ans = "";
        int pos = 0, ss = s.size(), step = 2*numRows-2;
        for(int i = 0; i < numRows; ++i){
            int inter = step - 2*i;
            for(int j = pos; j < ss; j += step){
                ans.push_back(s[j]);
                if(i == 0 || i == numRows-1)
                    continue;
                if(j + inter < ss)
                    ans.push_back(s[j + inter]);
            }
            ++pos;
        }
        return ans;
    }
};