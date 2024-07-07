class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int sz = s.size();
        string ans = "";
        for(const auto& str: dictionary){
            int ss = str.size(), as = ans.size(), j = 0;
            if(ss > sz || ss < as) continue;
            for(const auto& c: s){
                if(c == str[j] && ++j == ss){
                    if(ss > as)   ans = str;
                    else if(str < ans)   ans = str;
                    // else{
                    //     for(int i = 0; i < as; ++i){
                    //         if(str[i] == ans[i])  continue;
                    //         if(str[i] < ans[i])  ans = str;
                    //         break;
                    //     }
                    // }
                    break;
                }
            }
        }
        return ans;
    }
};