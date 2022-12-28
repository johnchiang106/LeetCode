class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(58,0);    //'A' ~ 'z' (there are six chars between 'Z' and 'a')
        int ss = s.size(), ts = t.size();
        if(ts > ss) return "";
        for(const auto& ch: t)
            --count[ch-'A'];

        string ans = s + "a";
        for(int i = 0, j = 0; j < ss; ++j){
            if(++count[s[j]-'A'] <= 0) --ts;
            
            if(ts == 0){
                while(count[s[i]-'A'] > 0)
                    --count[s[i]-'A'], ++i;
                if(j-i+1 < ans.size()) ans = s.substr(i,j-i+1);
            }
        }
        if(ans.size() >　ss)    return "";
        return ans;
    }
};